/* 
 * File:   COggLibMock.hpp
 * Author: artur
 *
 * Created on February 3, 2013, 12:44 PM
 */

#ifndef COGGLIBMOCK_HPP
#define	COGGLIBMOCK_HPP

#include <gmock/gmock.h>
#include <COggLibFacade.hpp>

using namespace eradio;

class COggLibMock : public COggLibFacade
{
public:
    MOCK_METHOD1(AllocateBuffer, u8*(u32 size));
    MOCK_METHOD1(SyncWrote, i32(u32 nBytes));
    MOCK_METHOD0(GetPage, i32());
    MOCK_METHOD0(InitStream, i32());
    MOCK_METHOD0(Page2Packets, i32());
    MOCK_METHOD0(GetPacket, i32());
    MOCK_METHOD0(InitRead, void());
    MOCK_METHOD1(ReadPacket, i64(const u32 nBits));
    MOCK_METHOD0(GetPacketBytesCount, u32());
};

#endif	/* COGGLIBMOCK_HPP */

