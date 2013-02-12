/* 
 * File:   COggContainer.hpp
 * Author: artur
 *
 * Created on December 16, 2012, 9:41 AM
 */

#ifndef COGGCONTAINER_HPP
#define	COGGCONTAINER_HPP

#include <gloDefs.hpp>
#include <CFileInputFacade.hpp>
#include <COggLibFacade.hpp>
#include <iostream>

namespace eradio
{

class COggContainer
{
private:
    typedef CFileInputFacade    CInput;
    typedef COggLibFacade       COggLib;
public:
    /**
     * 
     * @param[in] input         - input stream where OGG data will be read from
     * @param[in] ogg           - OGG object needed to decode OGG Container data
     */
    COggContainer(CInput&     input,
                    COggLib&    ogg);
    
    /**
     * 
     * @param output    buffer to write data to. It needs to be allocated with
     *                   at least nBytes bytes
     * @param nBytes    number of bytes to read to the buffer
     */
    void GetPayload(u8* output,
                     u32 nBytes);
    ~COggContainer();
private:
    void ReadInput();
    void GetPage();
    void GetPacket();
    void GetBytesFromPacket(u8* output);
    // number of bytes to read from a buffer in each
    u32         m_bufferSize;
    // buffer for OGG data
    u8*         m_buffer;
    // number of bytes not read from buffer. Mustn't be bigger than m_bufferSize
    u32         m_nBytesInBuffer;
    // stream with input data
    CInput&     m_input;
    // object for basic OGG Container data decoding
    COggLib&    m_ogg;

};

inline void COggContainer::GetBytesFromPacket(u8* output)
{
    u32 bytesInPacket = m_ogg.GetPacketBytesCount();
    while(bytesInPacket--)
    {
        *output++   = m_ogg.ReadPacket();
    }
}

} // namespace eradio

#endif	/* COGGCONTAINER_HPP */

