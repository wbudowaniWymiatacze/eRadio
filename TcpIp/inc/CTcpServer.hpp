/* 
 * File:   CTcpServer.hpp
 * Author: artur
 *
 * Created on November 6, 2012, 10:11 PM
 */

#ifndef CTCPSERVER_HPP
#define	CTCPSERVER_HPP

#include <map>
#include <gloDefs.hpp>

namespace eradio
{
namespace tcp
{

class CTcpClient;

struct SClientComp
{
    bool operator()(const u32& l,
                    const u32& r)
    {
        return l<r;
    }
};
    
class CTcpServer
{
public:
    void RegisterClient(CTcpClient& client);
    
    /**
     * calls client->receive() function when new data for the client listening
     * to the specified port is present
     */
    static void CallClient(u32         port,
                           u32*        buffer,
                           u32         len);

    void DeregisterClient(CTcpClient& client);
    
    typedef std::map<u32, CTcpClient&, SClientComp> TClientsMap;
    
private:
    typedef std::pair<u32, CTcpClient&> TClientPair;
    static TClientsMap m_clients;
};

} // namespace tcp
} // namespace eradio

#endif	/* CTCPSERVER_HPP */

