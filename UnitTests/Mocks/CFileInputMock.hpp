/* 
 * File:   CFileInputMock.hpp
 * Author: artur
 *
 * Created on February 3, 2013, 12:59 PM
 */

#ifndef CFILEINPUTMOCK_HPP
#define	CFILEINPUTMOCK_HPP

#include <gmock/gmock.h>
#include <CFileInputFacade.hpp>

using namespace eradio;

class CFileInputMock : public CFileInputFacade
{
public:
    CFileInputMock(ifstream& stream) :
        CFileInputFacade(stream)
    {
        
    }
        
    MOCK_CONST_METHOD2(read, bool(u8* buf, u32 size));
    MOCK_CONST_METHOD0(gcount, i32());
};

#endif	/* CFILEINPUTMOCK_HPP */

