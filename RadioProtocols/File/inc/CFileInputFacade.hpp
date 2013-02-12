/* 
 * File:   CFileInputFacade.hpp
 * Author: artur
 *
 * Created on February 3, 2013, 11:09 AM
 */

#ifndef CFILEINPUTFACADE_HPP
#define	CFILEINPUTFACADE_HPP

#include <fstream>
#include <gloDefs.hpp>

using namespace std;

namespace eradio
{

class CFileInputFacade
{
public:
    explicit CFileInputFacade(ifstream& stream) :
        m_inStream(stream) // initialize and open file
    {
            
    }
    
    virtual bool read(u8* buf,
                      u32 size) const
    {
        m_inStream.read(buf, size);
        return m_inStream.good();
    }
    
    virtual i32 gcount() const
    {
        return m_inStream.gcount();
    }
    
    virtual ~CFileInputFacade()
    {
        
    }
    
private:
    ifstream& m_inStream;
};

}

#endif	/* CFILEINPUTFACADE_HPP */

