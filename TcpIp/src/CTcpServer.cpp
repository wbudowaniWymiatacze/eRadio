/* 
 * File:   CTcpServer.cpp
 * Author: artur
 * 
 * Created on November 6, 2012, 10:11 PM
 */

#include <CTcpServer.hpp>
#include <CTcpClient.hpp>

namespace eradio
{
namespace tcp
{

// define static member
CTcpServer::TClientsMap CTcpServer::m_clients;

void CTcpServer::RegisterClient(CTcpClient& client)
{
    const u32 port = client.GetPort();
    m_clients.insert(TClientPair(port, client));
}

void CTcpServer::CallClient(u32     port,
                            u32*    buffer,
                            u32     len)
{
    if(CTcpServer::m_clients.find(port) != CTcpServer::m_clients.end())
    {
        CTcpClient& client = CTcpServer::m_clients.at(port);
        client.Receive(buffer, len);
    }
}

void CTcpServer::DeregisterClient(CTcpClient& client)
{
    TClientsMap::iterator it = m_clients.find(client.GetPort());
    if(it != m_clients.end())
    {
        m_clients.erase(it);
    }
}


} // namespace tcp
} // namespace eradio

