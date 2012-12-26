/* 
 * File:   SharedPtrTest.cpp
 * Author: artur
 *
 * Created on Dec 26, 2012, 9:35:36 PM
 */
#include <gtest/gtest.h>
#include <boost/shared_ptr.hpp>

/*
 * Simple C++ Test Suite
 */

typedef int                     TPtr;
typedef boost::shared_ptr<TPtr> TSharedPtr;

typedef unsigned int            u32;

class SharedPtrTest : public ::testing::Test
{
public:
    SharedPtrTest() : m_ptr(new TPtr)
    {
        
    }
    
    virtual ~SharedPtrTest()
    {
        
    }
    
    TSharedPtr& GetSharedPtr()
    {
        return m_ptr;
    }
    
protected:
    TSharedPtr    m_ptr;
};

TEST_F(SharedPtrTest, Reset)
{
    TPtr* newPtr    = new TPtr;
    
    // test for no argument reset
    m_ptr.reset();
    EXPECT_EQ(0, m_ptr.get());
    EXPECT_EQ((u32) 1, *m_ptr.shareRefCounter());
    
    m_ptr.reset(newPtr);
    EXPECT_EQ(newPtr, m_ptr.get());
    EXPECT_EQ((u32) 1, *m_ptr.shareRefCounter());
}

TEST_F(SharedPtrTest, CopyConstructor)
{
    TSharedPtr testedPtr(m_ptr);
    
    EXPECT_EQ(m_ptr.get(), testedPtr.get());
    EXPECT_EQ(m_ptr.shareRefCounter(), testedPtr.shareRefCounter());
    EXPECT_EQ((u32) 2, *testedPtr.shareRefCounter());
}

TEST_F(SharedPtrTest, Swap)
{
    TSharedPtr ptr0(new TPtr);
    TSharedPtr ptr1(new TPtr);
    TSharedPtr ptr2(ptr1);
    
    TPtr* ptr0OrigPtr = ptr0.get();
    TPtr* ptr1OrigPtr = ptr1.get();
    ptr1.swap(ptr0);

    EXPECT_EQ(ptr0OrigPtr, ptr1.get());
    EXPECT_EQ(ptr1OrigPtr, ptr0.get());
    EXPECT_EQ(ptr1OrigPtr, ptr2.get());
    EXPECT_EQ((u32) 2, *ptr0.shareRefCounter());
    EXPECT_EQ((u32) 1, *ptr1.shareRefCounter());
    EXPECT_EQ((u32) 2, *ptr2.shareRefCounter());
}

TEST_F(SharedPtrTest, SamePtrReset)
{
    TPtr* orgPtr    = m_ptr.get();
    m_ptr.reset(orgPtr);
    
    EXPECT_EQ(orgPtr, m_ptr.get());
    ASSERT_TRUE(m_ptr.shareRefCounter() != 0);
    EXPECT_EQ((u32) 1, *m_ptr.shareRefCounter());
}

TEST_F(SharedPtrTest, SamePtrSwap)
{
    TPtr* orgPtr    = m_ptr.get();
    m_ptr.swap(m_ptr);
    
    EXPECT_EQ(orgPtr, m_ptr.get());
    ASSERT_TRUE(m_ptr.shareRefCounter() != 0);
    EXPECT_EQ((u32) 1, *m_ptr.shareRefCounter());
}

// don't use it anywhere outside this file
struct STestStruct
{
    u32 i, j;
};

TEST_F(SharedPtrTest, operatorArrow)
{
    
    const u32 iVal  = 2;
    const u32 jVal  = 8;
    STestStruct testStruct = { iVal, jVal };
    
    STestStruct* newPtr    = new STestStruct;
    memcpy(newPtr, &testStruct, sizeof(STestStruct));
    
    boost::shared_ptr<STestStruct> newShPtr(newPtr);
    
    EXPECT_EQ(iVal, newShPtr->i);
    EXPECT_EQ(jVal, newShPtr->j);
}

// very dirty test. Don't do it at home kids
TEST_F(SharedPtrTest, DeleteNotShared)
{
    TSharedPtr* newShPtr0   = new TSharedPtr(new TPtr);
    TSharedPtr* newShPtr1   = newShPtr0;
    
    delete newShPtr0;
    
    // check the memory used previously by the destroyed shared array
    EXPECT_EQ((TPtr*) 0, newShPtr1->get());
    EXPECT_EQ((u32*) 0, newShPtr1->shareRefCounter());
}

TEST_F(SharedPtrTest, DeleteShared)
{
    TPtr* ptr               = m_ptr.get();
    TSharedPtr* newShPtr    = new TSharedPtr(m_ptr);
    
    delete newShPtr;
    
    EXPECT_EQ(ptr, m_ptr.get());
    EXPECT_EQ((u32) 1, *m_ptr.shareRefCounter());
}

