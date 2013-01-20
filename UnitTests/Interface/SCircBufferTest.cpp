/* 
 * File:   SCircBufferTest.cpp
 * Author: artur
 *
 * Created on Jan 12, 2013, 5:35:16 PM
 */
#include <SCircBuffer.hpp>
#include <gtest/gtest.h>

typedef int i32;

class SCircBufferTest : public ::testing::Test
{
public:
    
    typedef i32                    TBuffer;
    typedef SCircBuffer<TBuffer>   TCircBuffer;

    SCircBufferTest() :
        m_bufferLen(16),
        m_buffer(new(TBuffer[m_bufferLen])),
        m_circBuffer(m_buffer,
                     m_bufferLen),
        m_writeBufferLen(23),
        m_writeBuffer(new(TBuffer[m_writeBufferLen]))
    {
        for(i32 idx=0; idx<m_bufferLen; idx++)
        {
            m_buffer[idx] = idx;
        }
        
        for(i32 idx=0; idx<m_writeBufferLen; idx++)
        {
            m_writeBuffer[idx] = idx;
        }
    }
    
    ~SCircBufferTest()
    {
        delete[] m_writeBuffer;
        delete[] m_buffer;
    }
    
    // members for circular buffer initialization
    i32         m_bufferLen;
    TBuffer*    m_buffer;
    TCircBuffer m_circBuffer;
    
    // members for write buffer initialization
    i32         m_writeBufferLen;
    TBuffer*    m_writeBuffer;
};

/*
 * Tests reading data multiple times when the entire length of reads is smaller
 * than the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, ReadFewer)
{
    const i32 nReads        = 3;
    const i32 singleReadLen = m_bufferLen/nReads - 1;
    const i32 len           = nReads*singleReadLen;
    ASSERT_TRUE(len != 0);
    TBuffer readData[len];
    
    for(i32 readIdx=0; readIdx<nReads; readIdx++)
    {
        m_circBuffer.ReadData(&readData[readIdx*singleReadLen],
                              singleReadLen);
    }
    
    for(i32 idx=0; idx<len; idx++)
    {
        EXPECT_EQ(m_buffer[idx], readData[idx]);
    }
}

/*
 * Tests reading data multiple times when the entire length of reads is equal to
 * the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, ReadEqual)
{
    const i32 nReads        = 4;
    const i32 singleReadLen = m_bufferLen/nReads;
    const i32 len           = nReads*singleReadLen;
    ASSERT_TRUE(len == m_bufferLen);
    TBuffer readData[len];
    
    for(i32 readIdx=0; readIdx<nReads; readIdx++)
    {
        m_circBuffer.ReadData(&readData[readIdx*singleReadLen],
                              singleReadLen);
    }
    
    for(i32 idx=0; idx<len; idx++)
    {
        EXPECT_EQ(m_buffer[idx], readData[idx]);
    }
}

/*
 * Tests reading data multiple times when the entire length of reads is more
 * than the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, ReadMore)
{
    const i32 nReads        = 4;
    const i32 singleReadLen = m_bufferLen/nReads + 2;
    const i32 len           = nReads*singleReadLen;
    ASSERT_TRUE(len > m_bufferLen);
    TBuffer readData[len];
    
    for(i32 readIdx=0; readIdx<nReads; readIdx++)
    {
        m_circBuffer.ReadData(&readData[readIdx*singleReadLen],
                              singleReadLen);
    }
    
    for(i32 idx=0; idx<len; idx++)
    {
        EXPECT_EQ(m_buffer[idx % m_bufferLen], readData[idx]);
    }
}

/**
 * Tests operator[] with passing array index from
 * the range <0, 3*circularBufferLength>
 */
TEST_F(SCircBufferTest, OperatorBrackets)
{
    i32 maxIdxVal = 3*m_bufferLen;  
    
    for(i32 idx=0; idx<maxIdxVal; idx++)
    {
        EXPECT_EQ(idx % m_bufferLen, m_circBuffer[idx]);
    }
}

/*
 * Tests reading data multiple times when the entire length of reads is smaller
 * than the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, WriteFewer)
{
    const i32 nWrites           = 3;
    const i32 singleWriteLen    = m_bufferLen/nWrites - 1;
    const i32 len               = nWrites*singleWriteLen;
    ASSERT_TRUE(len != 0 && len <= m_writeBufferLen);
    
    for(i32 writeIdx=0; writeIdx<nWrites; writeIdx++)
    {
        m_circBuffer.WriteData(&m_writeBuffer[writeIdx*singleWriteLen],
                               singleWriteLen);
    }
    
    for(i32 idx=0; idx<len; idx++)
    {
        EXPECT_EQ(m_writeBuffer[idx], m_buffer[idx]);
    }
}

/*
 * Tests writing data multiple times when the entire length of writes is equal to
 * the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, WriteEqual)
{
    const i32 nWrites           = 4;
    const i32 singleWriteLen    = m_bufferLen/nWrites;
    const i32 len               = nWrites*singleWriteLen;
    ASSERT_TRUE(len == m_bufferLen && len <= m_writeBufferLen);
    
    for(i32 writeIdx=0; writeIdx<nWrites; writeIdx++)
    {
        m_circBuffer.WriteData(&m_writeBuffer[writeIdx*singleWriteLen],
                              singleWriteLen);
    }
    
    for(i32 idx=0; idx<len; idx++)
    {
        EXPECT_EQ(m_writeBuffer[idx], m_buffer[idx]);
    }
}

/*
 * Tests writing data multiple times when the entire length of writes is more
 * than the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, WriteMore)
{
    const i32 nWrites           = 4;
    const i32 singleWriteLen    = m_bufferLen/nWrites + 1;
    const i32 len               = nWrites*singleWriteLen;
    ASSERT_TRUE(len > m_bufferLen && len <= m_writeBufferLen);
    
    for(i32 writeIdx=0; writeIdx<nWrites; writeIdx++)
    {
        m_circBuffer.WriteData(&m_writeBuffer[writeIdx*singleWriteLen],
                               singleWriteLen);
    }
    
    i32 startIdx = len - m_bufferLen;
    for(i32 idx=0; idx<m_bufferLen; idx++)
    {
        EXPECT_EQ(m_writeBuffer[startIdx+idx], m_circBuffer[idx]);
    }
}
