/* 
 * File:   SharedArrayTest.cpp
 * Author: artur
 *
 * Created on Dec 23, 2012, 9:21:36 PM
 */
#include <gtest/gtest.h>
#include <boost/shared_array.hpp>

/*
 * Simple C++ Test Suite
 */

typedef int                         TArr;
typedef boost::shared_array<TArr>   TSharedArray;

typedef unsigned int                u32;

const int g_arrSize = 10;

class SharedArrayTest : public ::testing::Test
{
public:
    SharedArrayTest() : m_arr(new TArr[g_arrSize])
    {
        
    }
    
    virtual ~SharedArrayTest()
    {
        
    }
    
    TSharedArray& GetSharedArray()
    {
        return m_arr;
    }
    
protected:
    TSharedArray    m_arr;
};

TEST_F(SharedArrayTest, Reset)
{
    TArr* newArr    = new TArr[g_arrSize];
    
    // test for no argument reset
    m_arr.reset();
    EXPECT_EQ(0, m_arr.get());
    
    m_arr.reset(newArr);
    EXPECT_EQ(newArr, m_arr.get());
}

TEST_F(SharedArrayTest, CopyConstructor)
{
    TSharedArray testedArray(m_arr);
    
    EXPECT_EQ(m_arr.get(), testedArray.get());
    EXPECT_EQ((u32) 2, testedArray.use_count());
}

TEST_F(SharedArrayTest, Swap)
{
    TSharedArray arr0(new TArr[g_arrSize]);
    TSharedArray arr1(new TArr[g_arrSize]);
    TSharedArray arr2(arr1);
    
    TArr* arr0OrigPtr = arr0.get();
    TArr* arr1OrigPtr = arr1.get();
    arr1.swap(arr0);

    EXPECT_EQ(arr0OrigPtr, arr1.get());
    EXPECT_EQ(arr1OrigPtr, arr0.get());
    EXPECT_EQ(arr1OrigPtr, arr2.get());
    EXPECT_EQ((u32) 2, arr0.use_count());
    EXPECT_EQ((u32) 1, arr1.use_count());
    EXPECT_EQ((u32) 2, arr2.use_count());
}

TEST_F(SharedArrayTest, SamePtrReset)
{
    TArr* orgPtr    = m_arr.get();
    m_arr.reset(orgPtr);
    
    EXPECT_EQ(orgPtr, m_arr.get());
    EXPECT_EQ((u32) 1, m_arr.use_count());
}

TEST_F(SharedArrayTest, SamePtrSwap)
{
    TArr* orgPtr    = m_arr.get();
    m_arr.swap(m_arr);
    
    EXPECT_EQ(orgPtr, m_arr.get());
    EXPECT_EQ((u32) 1, m_arr.use_count());
}

TEST_F(SharedArrayTest, squareBrackets)
{
    TArr arr[g_arrSize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    TArr* newArr        = new TArr[g_arrSize];
    memcpy(newArr, arr, sizeof(arr));
    
    m_arr.reset(newArr);
    
    for(int idx=0; idx<g_arrSize; idx++)
    {
        EXPECT_EQ(arr[idx], m_arr[idx]);
    }
}

TEST_F(SharedArrayTest, DeleteShared)
{
    TArr* arrPtr            = m_arr.get();
    TSharedArray* arr       = new TSharedArray(m_arr);
    
    delete arr;
    
    EXPECT_EQ(arrPtr, m_arr.get());
    EXPECT_EQ((u32) 1, m_arr.use_count());
}

