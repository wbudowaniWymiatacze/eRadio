/* 
 * File:   sCircBuffer.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 10:16 PM
 */

#ifndef SCIRCBUFFER_HPP
#define	SCIRCBUFFER_HPP

#include <gloDefs.hpp>
#include <boost/shared_array.hpp>

namespace eradio
{

/**
 * Implements circular buffer with functions to write and read data
 * @param T type of buffer
 */
template< typename T >
struct SCircBuffer
{
public:
    /**
     * Creates circular buffer and initiates pointers
     * @param len       length of the circular buffer
     */
    SCircBuffer(::boost::shared_array<T> buf,
                u32                         len) :
        m_buffer(buf)
    {
        m_curPointer    = m_buffer.get();
        m_endPointer    = m_buffer.get() + len;
    }
        
    /**
     * Reads the data from the circular buffer
     * @param data  points to the buffer where the data will be saved to
     * @param len   length of the data to be read
     */
    void ReadData(T*   data,
                  u32  len)
    {
        // check if there's enough space for the data
        // up till the end of the buffer
        if(len<=m_curPointer-m_endPointer+1)
        {
            memcpy(data, m_curPointer, len);
            m_curPointer += len;
        }
        else
        {
            // get the amount of data that may be loaded
            // up till the end of the buffer
            u32 curLen = m_curPointer-m_endPointer+1;
            memcpy(data, m_curPointer, curLen);
            data += curLen;
            
            // calculate how much data still needs to be loaded
            curLen = len - curLen;
            memcpy(data, m_buffer.get(), curLen);
            m_curPointer = m_buffer.get() + curLen;
        }
    }
        
    /**
     * Stores data in the circular buffer
     * 
     * @param data  points the data to be stored
     * @param len   length of the data to be stored
     */
    void WriteData(T*   data,
                   u32  len)
    {
        // check if there's enough space for the data
        // up till the end of the buffer
        if(len<=m_curPointer-m_endPointer+1)
        {
            memcpy(m_curPointer, data, len);
            m_curPointer += len;
        }
        else
        {
            // get the amount of data that may be stored
            // up till the end of the buffer
            u32 curLen = m_curPointer-m_endPointer+1;
            memcpy(m_curPointer, data, curLen);
            data += curLen;
            
            // calculate how much data still needs to be stored
            curLen = len - curLen;
            memcpy(m_buffer.get(), data, curLen);
            m_curPointer = m_buffer.get() + curLen;
        }
    }
    
private:
    ::boost::shared_array<T> m_buffer;
    T*                          m_curPointer;
    T*                          m_endPointer;
};

} // namespace eradio

#endif	/* SCIRCBUFFER_HPP */

