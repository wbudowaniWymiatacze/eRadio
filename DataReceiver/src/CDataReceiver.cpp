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
                             ::boostmod::shared_array<u32>  audioBuffer,
                             u32                            bufLen) :
    m_dataRcvState(0), //TODO
    m_audioBuffer(audioBuffer, bufLen)
{
    tcpServer.RegisterClient(*this);
}

u32 CDataReceiver::Receive(u32* buffer,
                            u32 len)
{
    
}

CDataReceiver::~CDataReceiver()
{
}

} // namespace eradio

