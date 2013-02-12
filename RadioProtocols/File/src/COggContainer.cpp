/* 
 * File:   COggContainer.cpp
 * Author: artur
 * 
 * Created on December 16, 2012, 9:41 AM
 */

#include <COggContainer.hpp>
#include <CFileInputFacade.hpp>
#include <stdlib.h>
#include <iostream>

namespace eradio
{

COggContainer::COggContainer(CInput&    input,
                             COggLib&   ogg) :
    m_bufferSize(4096),   // from Vorbis example: decoder_example.c
    m_nBytesInBuffer(m_bufferSize),
    m_input(input),
    m_ogg(ogg)
{
    // allocate buffer
    m_buffer    = m_ogg.AllocateBuffer(m_bufferSize);
    
    // initiate buffer, page and packet
    ReadInput();
    GetPage();
    GetPacket();
}

void COggContainer::GetPayload(u8* output,
                               u32 nBytes)
{
    u8* tmp = output;
    u32 bytesInPacket = m_ogg.GetPacketBytesCount();
    while(nBytes>bytesInPacket)
    {
        // get all the data from the current packet
        m_ogg.InitRead();
        GetBytesFromPacket(tmp);
        nBytes  -= bytesInPacket;
        tmp     += bytesInPacket;
        
        // get next packet in case more data is needed
        GetPacket();
        
        bytesInPacket = m_ogg.GetPacketBytesCount();
    }
    
    // get the rest of the requested data
    m_ogg.InitRead();
    GetBytesFromPacket(tmp); 
}

void COggContainer::ReadInput()
{
    // read to the buffer
    m_input.read(m_buffer,
                 m_bufferSize);
    
    // tell OGG how many bytes were read successfully
    m_ogg.SyncWrote(m_input.gcount());
}

void COggContainer::GetPage()
{
    // try to get a page from current buffer
    i32 status  = m_ogg.GetPage();
    // if needed read more data to the buffer and try to get a full page
    while(status == 0)
    {
        ReadInput();
        status  = m_ogg.GetPage();
    }
    
    // initialize stream and set serial number
    m_ogg.InitStream();
    
    // break the page into packets
    status = m_ogg.Page2Packets();
    
    if(status == -1)
    {
        std::cout<<"Reading a page returned -1"<<std::endl;
        exit(1);
    }
}

void COggContainer::GetPacket()
{
    const u32 nMaxAttempts = 10;
    i32 status = m_ogg.GetPacket();
    
    u32 nAttempts = 0;
    // subsequent call to GetPacket should succeed
    for(;status == -1 && nAttempts<nMaxAttempts; nAttempts++)
    {
        status = m_ogg.GetPacket();
    }
    
    nAttempts = 0;
    for(;status == 0 && nAttempts<nMaxAttempts; nAttempts++)
    {
        // if a new page is needed get it and get a full packet
        GetPage();
        status = m_ogg.GetPacket();
    }
}

COggContainer::~COggContainer()
{
}

} // namespace eradio

