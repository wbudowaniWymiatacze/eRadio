/* 
 * File:   CDataReceiver.hpp
 * Author: artur
 *
 * Created on November 7, 2012, 10:15 PM
 */

#ifndef CDATARECEIVER_HPP
#define	CDATARECEIVER_HPP

#include <gloDefs.hpp>
#include <CTcpClient.hpp>
#include <SCircBuffer.hpp>

namespace eradio
{

namespace boostmod
{
template <typename u32> class shared_array;
}

class IDataReceiverState;

namespace tcp
{
class CTcpServer;
}

class CDataReceiver : public tcp::CTcpClient
{
public:
    CDataReceiver(tcp::CTcpServer&              tcpServer,
                  ::boostmod::shared_array<u32> audioBuffer,
                  u32                           bufLen);
    
    /**
     * Stores data received through TCP/IP to the audio buffer
     * @param buffer    points the input data
     * @param len       length of the input data
     * @return 
     */
    virtual u32 Receive(u32*    buffer,
                         u32     len);
    virtual ~CDataReceiver();
private:
    IDataReceiverState*     m_dataRcvState;
    
    // circular buffer for storing samples received through TCP/IP
    SCircBuffer<audioBufT>  m_audioBuffer;
};

} // namespace eradio

#endif	/* CDATARECEIVER_HPP */

