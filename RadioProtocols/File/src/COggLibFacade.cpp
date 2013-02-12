/* 
 * File:   COggLibFacade.cpp
 * Author: artur
 * 
 * Created on January 31, 2013, 8:52 PM
 */

#include <COggLibFacade.hpp>
#include <cstring>  // memset

namespace eradio
{

COggLibFacade::COggLibFacade()
{
    ogg_sync_init(&m_syncState);
    // for some reason ogg_stream_reset doesn't work. Replaced with memset
    memset(&m_streamState, 0, sizeof(m_streamState));
}

COggLibFacade::COggLibFacade(const COggLibFacade& other)
{
    m_syncState = other.m_syncState;
}

u8* COggLibFacade::AllocateBuffer(u32 size)
{
    return static_cast<u8*>(ogg_sync_buffer(&m_syncState,
                                            size));
}

i32 COggLibFacade::SyncWrote(u32 nBytes)
{
    return ogg_sync_wrote(&m_syncState,
                          nBytes);
}

i32 COggLibFacade::GetPage()
{
    return ogg_sync_pageout(&m_syncState,
                            &m_page);
}

i32 COggLibFacade::InitStream()
{
    return ogg_stream_init(&m_streamState,
                           ogg_page_serialno(&m_page));
}

i32 COggLibFacade::Page2Packets()
{
    return ogg_stream_pagein(&m_streamState,
                             &m_page);
}

i32 COggLibFacade::GetPacket()
{
    return ogg_stream_packetout(&m_streamState,
                                &m_packet);
}

void COggLibFacade::InitRead()
{
    oggpack_readinit(&m_packetBuffer,
                     m_packet.packet,
                     m_packet.bytes);
}

i64 COggLibFacade::ReadPacket(const u32 nBits)
{
    return oggpack_read(&m_packetBuffer,
                        nBits);
}

u32 COggLibFacade::GetPacketBytesCount()
{
    return m_packet.bytes;
}

COggLibFacade::~COggLibFacade()
{
    // check if the stream was correctly initialized
    if(ogg_stream_check(&m_streamState) == 0)
    {
        ogg_stream_clear(&m_streamState);
    }
    ogg_sync_clear(&m_syncState);
}

}

