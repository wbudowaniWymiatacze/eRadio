/* 
 * File:   CHttpClient.hpp
 * Author: artur
 *
 * Created on November 7, 2012, 9:43 PM
 */

#ifndef CHTTPCLIENT_HPP
#define	CHTTPCLIENT_HPP

#include <CTcpClient.hpp>

namespace eradio
{

namespace tcp
{
class CTcpServer;
}

class CHttpClient : public tcp::CTcpClient
{
public:
    CHttpClient(const char* hostname,
                tcp::CTcpServer& tcpServer);
    void Get(char* command);
    virtual ~CHttpClient();
private:

};

} // namespace eradio

#endif	/* CHTTPCLIENT_HPP */

