/* 
 * File:   sCircBuffer.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 10:16 PM
 */

#ifndef SCIRCBUFFER_HPP
#define	SCIRCBUFFER_HPP

/**
 * Implements circular buffer with functions to write and read data
 * @param T type of buffer
 */
template< typename T >
struct SCircBuffer
{
private:
    typedef unsigned int u32;
    
public:
    /**
     * Creates circular buffer and initiates pointers
     * @param len       length of the circular buffer
     */
    SCircBuffer(T*  buf = 0,
                u32  len = 0) :
        m_buffer(buf),
        m_curPointer(buf),
        m_endPointer(buf + len),
        m_length(len),
        m_startOffset(0)
    {
            
    }
    
    /**
     * Returns value at given index of the circular buffer in the sequence
     * the data was written to the circular buffer. If index is bigger
     * than the length of the buffer, value at
     * idx % (circular buffer length) is returned
     * @param idx   index of the circular buffer
     * @return value at the given index modulo (circular buffer length)
     */
    T operator[](u32 idx)
    {
        return m_buffer[(m_startOffset + idx) % m_length];
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
        if(len<=static_cast<u32>(m_endPointer-m_curPointer)+1)
        {
            memcpy(data, m_curPointer, len*sizeof(T));
            m_curPointer += len;
        }
        else
        {
            // get the amount of data that may be loaded
            // up till the end of the buffer
            u32 curLen = static_cast<u32>(m_endPointer-m_curPointer);
            memcpy(data, m_curPointer, curLen*sizeof(T));
            data += curLen;
            
            // calculate how much data still needs to be loaded
            curLen = len - curLen;
            memcpy(data, m_buffer, curLen*sizeof(T));
            m_curPointer = m_buffer + curLen;
        }
        
        m_startOffset = static_cast<u32>(m_curPointer - m_buffer);
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
        if(len<=static_cast<u32>(m_endPointer-m_curPointer)+1)
        {
            memcpy(m_curPointer, data, len*sizeof(T));
            m_curPointer += len;
        }
        else
        {
            // get the amount of data that may be stored
            // up till the end of the buffer
            u32 curLen = static_cast<u32>(m_endPointer-m_curPointer);
            memcpy(m_curPointer, data, curLen*sizeof(T));
            data += curLen;
            
            // calculate how much data still needs to be stored
            curLen = len - curLen;
            memcpy(m_buffer, data, curLen*sizeof(T));
            m_curPointer = m_buffer + curLen;
        }
        
        m_startOffset = static_cast<u32>(m_curPointer - m_buffer);
    }
    
public:
    T*  m_buffer;
    T*  m_curPointer;
    T*  m_endPointer;
    u32 m_length;
    u32 m_startOffset;  // = (u32)(m_curPointer - m_buffer)
};

#endif	/* SCIRCBUFFER_HPP */

