/* 
 * File:   CDataReceiver.cpp
 * Author: artur
 * 
 * Created on November 7, 2012, 10:15 PM
 */

#include <CDataReceiver.hpp>
#include <CTcpServer.hpp>

namespace eradio
{

CDataReceiver::CDataReceiver(tcp::CTcpServer&               tcpServer,
                             ::boost::shared_array<u32>  audioBuffer,
                             u32                            bufLen) :
    m_dataRcvState(0), //TODO
    m_audioBuffer(audioBuffer.get(), bufLen)
{
    tcpServer.RegisterClient(*this);
}

u32 CDataReceiver::Receive(u32* buffer,
                            u32 len)
{
    (void) buffer;
    (void) len;
    
    return 0;
}

CDataReceiver::~CDataReceiver()
{
}

} // namespace eradio

