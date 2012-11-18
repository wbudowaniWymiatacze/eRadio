/* 
 * File:   CTcpClient.hpp
 * Author: artur
 *
 * Created on November 6, 2012, 9:39 PM
 */

#ifndef CTCPCLIENT_HPP
#define	CTCPCLIENT_HPP

#include <gloDefs.hpp>

namespace eradio
{
namespace tcp
{

class CTcpClient
{
public:
    CTcpClient()
    {
        
    }
    
    CTcpClient(const char* hostname,
               u32   port);
    
    void send(u32* buffer,
              u32  len);
    
    virtual u32 Receive(u32* buffer,
                        u32 len) = 0;
    u32 GetPort() const
    {
        return m_port;
    }
    
    virtual ~CTcpClient();
    
private:
    
    const char*   m_host;
    u32     m_port;
}; // class CTcpClient

} // namespace tcp
} // namespace eradio

#endif	/* CTCPCLIENT_HPP */

