/* 
 * File:   CHttpClient.cpp
 * Author: artur
 * 
 * Created on November 7, 2012, 9:43 PM
 */

#include <CHttpClient.hpp>
#include <CTcpServer.hpp>

namespace eradio
{

// standard HTTP port
const u32 httpPort = 8080;

CHttpClient::CHttpClient(const char* hostname,
                         tcp::CTcpServer& tcpServer) :
    tcp::CTcpClient(hostname,
                    httpPort)
{
    tcpServer.RegisterClient(*this);
}

CHttpClient::~CHttpClient()
{
}

} // namespace eradio

