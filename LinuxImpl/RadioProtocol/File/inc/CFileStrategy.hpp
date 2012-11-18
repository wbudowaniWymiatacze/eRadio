/* 
 * File:   CFileStrategy.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 11:57 PM
 */

#ifndef CFILESTRATEGY_HPP
#define	CFILESTRATEGY_HPP

#include <iostream>
#include <fstream>

#include <scoped_ptr.hpp>
#include <IRadioStrategy.hpp>

namespace eradio
{

namespace tcp
{
class CTcpServer;
}

class CFileStrategy : public IRadioStrategy
{
public:
    CFileStrategy(tcp::CTcpServer&  tcpServer,
                  const char*       url);
    
    // TODO
    u32 GetInPort()
    {
        return 0;
    }
    
    void Play();
    void Pause();
    void Stop();
    virtual ~CFileStrategy();

private:
    scoped_ptr<std::ifstream> m_file;
};

}

#endif	/* CFILESTRATEGY_HPP */

