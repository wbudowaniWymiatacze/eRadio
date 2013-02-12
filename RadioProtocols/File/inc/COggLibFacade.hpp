/* 
 * File:   COggLibFacade.hpp
 * Author: artur
 *
 * Created on January 31, 2013, 8:52 PM
 */

#ifndef COGGLIBFACADE_HPP
#define	COGGLIBFACADE_HPP
#include <gloDefs.hpp>
#include <ogg/ogg.h>

namespace eradio
{

class COggLibFacade
{
public:
    /**
     * Initializes sync state
     */
    COggLibFacade();
    
    COggLibFacade(const COggLibFacade& other);
    
    /**
     * Allocates buffer of a proper size
     * 
     * @param[in] size  - number of bytes to allocate
     * @return            pointer to the allocated buffer
     */
    virtual u8* AllocateBuffer(u32 size);
    
    /**
     * Inform OGG library of how many bytes were written into the 
     * buffer
     * 
     * @param[in] nBytes    - number of bytes that were written
     * @return -1           - overflow or internal error
     *          0            - all other cases
     */
    virtual i32 SyncWrote(u32 nBytes);
    
    /**
     * Attempt to get a full page from the current data in the 
     * buffer
     * 
     * @return -1   - stream not in sync
     *          0    - more data needed or internal error
     *          1    - a page was returned
     * 
     */
    virtual i32 GetPage();
    
    /**
     * Initialize stream and set serial number
     * 
     * @return -1   failure
     *          0    success
     */
    virtual i32 InitStream();
    
    /**
     * Breaks a page into packets
     * 
     * @return -1   failure
     *          0    success
     */
    virtual i32 Page2Packets();
    
    /**
     * Extracts a packet from the current pages
     * 
     * @return -1   - out of sync or a gap in the data. Try call 
     *                 the function again and it should succeed
     *          0    - insufficient data or internal error
     *          1    - success
     */
    virtual i32 GetPacket();
    
    /**
     * Prepares OGG buffer for reading
     */
    virtual void InitRead();
    
    /**
     * Reads number of bits from an extracted packet
     * 
     * @param[in] nBits     - number of bits to read
     * @return              - requested bits
     * 
     */
    virtual i64 ReadPacket(const u32 nBits = 8);
    
    /**
     * Returns the number of bytes in the current packet
     * @return number of bytes in a packet
     */
    virtual u32 GetPacketBytesCount();
    
    /**
     * Clears stream and sync structure
     */
    virtual ~COggLibFacade();
private:
    // sync and verify incoming physical bitstream */
    ogg_sync_state      m_syncState;
    // take physical pages, weld into a logical stream of packets
    ogg_stream_state    m_streamState;
    // one OGG bitstream page. Vorbis packets are inside */
    ogg_page            m_page;
    // one raw packet of data for decode
    ogg_packet          m_packet;
    // OGG buffer
    oggpack_buffer      m_packetBuffer;

};

}

#endif	/* COGGLIBFACADE_HPP */

