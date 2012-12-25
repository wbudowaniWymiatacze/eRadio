/* 
 * File:   COggContainer.cpp
 * Author: artur
 * 
 * Created on December 16, 2012, 9:41 AM
 */

#include <COggContainer.hpp>
#include <ogg/ogg.h>
#include <iostream>
#include <string.h> // for memset
#include <stdlib.h>

namespace eradio
{

COggContainer::COggContainer(std::istream&  input) :
    m_bufferSize(4096),   // from Vorbis example: decoder_example.c
    m_nBytesInBuffer(m_bufferSize),
    m_input(input)
{
    ogg_sync_init(&m_syncState);
    
    // allocate buffer
    m_buffer    = static_cast<u8*>(ogg_sync_buffer(&m_syncState,
                                                   m_bufferSize));
    
//    memset(&m_syncState, 0, sizeof(m_syncState));
//    memset(&m_streamState, 0, sizeof(m_streamState));
//    memset(&m_page, 0, sizeof(m_page));
//    memset(&m_packet, 0, sizeof(m_packet));
    
    // initiate buffer, page and packet
    ReadInput();
    GetPage();
    GetPacket();
}

void COggContainer::GetPayload(u8* output,
                               i32 nBytes)
{
    oggpack_buffer packetBuffer;
    
    while(nBytes>=m_packet.bytes)
    {
        // get all the data from the current packet
        oggpack_readinit(&packetBuffer,
                         m_packet.packet,
                         m_packet.bytes);
        GetBytesFromPacket(&packetBuffer,
                           output,
                           m_packet.bytes);
        nBytes -= m_packet.bytes;
        
        GetPacket();
    }
    
    // get the rest of the requested data
    oggpack_readinit(&packetBuffer,
                     m_packet.packet,
                     m_packet.bytes);
    GetBytesFromPacket(&packetBuffer,
                       output,
                       nBytes);   
}

void COggContainer::ReadInput()
{
    // read to the buffer
    m_input.read(m_buffer,
                 m_bufferSize);
    
    // tell OGG how many bytes were read successfully
    ogg_sync_wrote(&m_syncState,
                   m_input.gcount());
}

void COggContainer::GetPage()
{
    // try to get a page from current buffer
    i32 status  = ogg_sync_pageout(&m_syncState,
                                   &m_page);
    // if needed read more data to the buffer and try to get a full page
    while(status == 0)
    {
        ReadInput();
        status  = ogg_sync_pageout(&m_syncState,
                                   &m_page);
    }
    
    // initialize stream and set serial number
    ogg_stream_init(&m_streamState,
                    ogg_page_serialno(&m_page));
    
    // break the page into packets
    status =    ogg_stream_pagein(&m_streamState,
                                  &m_page);
    
    if(status == -1)
    {
        std::cout<<"Reading a page returned -1"<<std::endl;
        exit(1);
    }
}

void COggContainer::GetPacket()
{
    // try to get a packet from the current page
    while(ogg_stream_packetout(&m_streamState,
                               &m_packet) == -1)
    {
        // if a new page is needed get it and get a full packet
        GetPage();
    }
}

COggContainer::~COggContainer()
{
    ogg_stream_clear(&m_streamState);
    ogg_sync_clear(&m_syncState);
}

} // namespace eradio

