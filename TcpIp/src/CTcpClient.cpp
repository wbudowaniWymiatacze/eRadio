/* 
 * File:   CTcp.cpp
 * Author: artur
 * 
 * Created on November 6, 2012, 9:39 PM
 */

#include <CTcpClient.hpp>

namespace eradio
{
namespace tcp
{

CTcpClient::CTcpClient(const char* hostname,
                       u32 port) :
    m_host(hostname),
    m_port(port)
{
}

void CTcpClient::send(u32* buffer, u32 len)
{
    
}

CTcpClient::~CTcpClient() {
}

} // namespace tcp
} // namespace eradio

