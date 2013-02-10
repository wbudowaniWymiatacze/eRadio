#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <CFileInputMock.hpp>
#include <COggLibMock.hpp>
#include <COggContainer.hpp>
#include <fstream>

using namespace std;
using namespace eradio;
using namespace ::testing;

/**
 * Tests functionality if all needed data is in OGG buffer
 */
TEST(OGGContainer, EnoughDataIn1Read)
{
    char output[]       = "bbbbb";
    const char ref[]    = "aaaaa";
    const u32 nBytes    = strlen(output);
    
    COggLibMock oggLib;
    
    ifstream inStream("../Makefile");
    CFileInputMock  fileInput(inStream);
    
    /*
     * define OGG Lib mock expectations
     */
    // called in COggContainer()
    EXPECT_CALL(oggLib, AllocateBuffer(_))
        .Times(1)
        .WillRepeatedly(Return((u8*) 0));
    // called in COggContainer{ ReadInput() }
    EXPECT_CALL(oggLib, SyncWrote(nBytes))
        .Times(1)
        .WillRepeatedly(Return(0));
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, GetPage())
        .Times(1)
        .WillRepeatedly(Return(1));
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, InitStream())
        .Times(1);
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, Page2Packets())
        .Times(1)
        .WillRepeatedly(Return(1));
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, GetPacket())
        .Times(1)
        .WillRepeatedly(Return(1));
        
    // called in GetPayload()
    EXPECT_CALL(oggLib, InitRead())
        .Times(1);
    // called in GetPayload() and GetBytesFromPacket()
    EXPECT_CALL(oggLib, GetPacketBytesCount())
        .Times(2)
        .WillRepeatedly(Return(nBytes));
    EXPECT_CALL(oggLib, ReadPacket(_))
        .Times(nBytes)
        .WillRepeatedly(Return('a'));
        
    /*
     * define file input mock expectations
     */
    // called in COggContainer(){ ReadInput() }
    EXPECT_CALL(fileInput, read(_, _))
        .Times(1);
    // called in COggContainer(){ ReadInput() }
    EXPECT_CALL(fileInput, gcount())
        .Times(1)
        .WillRepeatedly(Return(nBytes));
        
    COggContainer ogg(fileInput, oggLib);
    
    ogg.GetPayload(output, nBytes);
    
    inStream.close();
    
    EXPECT_TRUE(!strcmp(output, ref));
}

/**
 * Tests functionality when additional packet needs to be read from a page
 */
TEST(OggContainer, AdditionalPacket)
{
    const u32 nBytes        = 5;
    const u32 nReadInCalled = nBytes-1 + nBytes;
    char output[nReadInCalled+1];
    
    COggLibMock oggLib;
    
    ifstream inStream("../Makefile");
    CFileInputMock  fileInput(inStream);
    
    /*
     * define OGG Lib mock expectations
     */
    // called in COggContainer()
    EXPECT_CALL(oggLib, AllocateBuffer(_))
        .Times(1)
        .WillRepeatedly(Return((u8*) 0));
    // called in COggContainer{ ReadInput() }
    EXPECT_CALL(oggLib, SyncWrote(nBytes))
        .Times(1);
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, GetPage())
        .Times(1)
        .WillRepeatedly(Return(1));
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, InitStream())
        .Times(1);
    // called in COggContainer{ GetPage() }
    EXPECT_CALL(oggLib, Page2Packets())
        .Times(1)
        .WillRepeatedly(Return(1));
    // called in COggContainer{ GetPage() }
    // and in GetPayload
    EXPECT_CALL(oggLib, GetPacket())
        .Times(2)
        .WillRepeatedly(Return(1));
        
    // called in GetPayload()
    EXPECT_CALL(oggLib, InitRead())
        .Times(2);
    // called in GetPayload() x3 and GetBytesFromPacket() x2
    EXPECT_CALL(oggLib, GetPacketBytesCount())
        .Times(4)
        // to indicate additional packet needs to be read
        .WillOnce(Return(nBytes-1))
        // returned in the first call in GetBytesFromPacket()
        .WillOnce(Return(nBytes-1))
        .WillRepeatedly(Return(nBytes));
    EXPECT_CALL(oggLib, ReadPacket(_))
        // number of times is the sum of return values of GetPacketBytesCount()
        // called in GetBytesFromPacket()
        .Times(nReadInCalled)
        .WillRepeatedly(Return('a'));
    
    // size = number of times ReadPacket() is called +1 for \0
    char ref[nReadInCalled +1] = "a";
    for(u32 idx=0; idx<nReadInCalled-1; idx++)
    {
        strcat(ref, "a");
    }
        
    /*
     * define file input mock expectations
     */
    // called in COggContainer(){ ReadInput() }
    EXPECT_CALL(fileInput, read(_, _))
        .Times(1);
    // called in COggContainer(){ ReadInput() }
    EXPECT_CALL(fileInput, gcount())
        .Times(1)
        .WillRepeatedly(Return(nBytes));
        
    COggContainer ogg(fileInput, oggLib);
    
    ogg.GetPayload(output, nBytes);
    
    EXPECT_TRUE(!strncmp(output, ref, nReadInCalled));
    
}

/*
 * test na:
 * + dodatkową stronę
 * + dodatkowy odczyt ze strumienia
 * + brak dodatkowych stron
 * + brak dodatkowych pakietów
 * + brak dodatkowych danych ze strumienia
 */
