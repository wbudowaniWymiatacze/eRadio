/* 
 * File:   COggContainer.hpp
 * Author: artur
 *
 * Created on December 16, 2012, 9:41 AM
 */

#ifndef COGGCONTAINER_HPP
#define	COGGCONTAINER_HPP

#include <gloDefs.hpp>
#include <iostream>
#include <ogg/ogg.h>

namespace eradio
{

//struct ogg_sync_state;
//struct ogg_stream_state;
//struct ogg_page;
//struct ogg_packet;

class COggContainer
{
public:
    /**
     * 
     * @param input         - input stream where OGG data will be read from
     */
    COggContainer(std::istream& input);
    
    /**
     * 
     * @param output    buffer to write data to. It needs to be allocated with
     *                   at least nBytes bytes
     * @param nBytes    number of bytes to read to the buffer
     */
    void GetPayload(u8* output,
                     i32 nBytes);
    ~COggContainer();
private:
    void ReadInput();
    void GetPage();
    void GetPacket();
    void GetBytesFromPacket(oggpack_buffer* packetBuffer,
                              u8*             output,
                              i32             nBytes);
    // sync and verify incoming physical bitstream */
    ogg_sync_state      m_syncState;
    // take physical pages, weld into a logical stream of packets
    ogg_stream_state    m_streamState;
    // one OGG bitstream page. Vorbis packets are inside */
    ogg_page            m_page;
    // one raw packet of data for decode
    ogg_packet          m_packet;
    // number of bytes to read from a buffer in each
    u32                 m_bufferSize;
    // buffer for OGG data
    u8*                 m_buffer;
    // number of bytes not read from buffer. Mustn't be bigger than m_bufferSize
    u32                 m_nBytesInBuffer;
    // stream with input data
    std::istream&       m_input;

};

inline void COggContainer::GetBytesFromPacket(oggpack_buffer* packetBuffer,
                                                u8*             output,
                                                i32             nBytes)
{
    const i32 oggByteSize   = 8;
    while(nBytes--)
    {
        *output++   = oggpack_read(packetBuffer,
                                   oggByteSize);
    }
}

} // namespace eradio

#endif	/* COGGCONTAINER_HPP */

