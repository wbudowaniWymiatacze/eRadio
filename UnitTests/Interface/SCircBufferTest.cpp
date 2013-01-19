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
                 m_bufferLen)
    {
        for(i32 idx=0; idx<m_bufferLen; idx++)
        {
            m_buffer[idx] = idx;
        }
    }
    
    i32         m_bufferLen;
    TBuffer*    m_buffer;
    TCircBuffer m_circBuffer;
};

/*
 * Tests reading data multiple times when the entire length of reads is smaller
 * than the amount of data in the circular buffer
 */
TEST_F(SCircBufferTest, Read0)
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
TEST_F(SCircBufferTest, Read1)
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
TEST_F(SCircBufferTest, Read2)
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
