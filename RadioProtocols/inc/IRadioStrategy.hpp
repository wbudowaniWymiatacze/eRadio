/* 
 * File:   IRadioStrategy.hpp
 * Author: artur
 *
 * Created on November 6, 2012, 10:01 PM
 */

#ifndef IRADIOSTRATEGY_HPP
#define	IRADIOSTRATEGY_HPP

#include <gloDefs.hpp>
#include <boost/scoped_ptr.hpp>

#include <CTcpClient.hpp>
#include <CDataReceiver.hpp>
#include <CAudioOut.hpp>

using namespace boost;

namespace eradio
{
    
class IRadioStrategy
{
    
public:
    IRadioStrategy(const char* url) :
        m_url(const_cast<char*>(url)),
        m_dataRcvr(0),
        m_audioOut(0),
        m_inPort(0)
    {
        
    }
    
    /**
     * returns the input port for given Radio protocol
     */
    virtual u32 GetInPort()
    {
        return m_inPort;
    }
    
    virtual void Play() = 0;
    virtual void Pause() = 0;
    virtual void Stop() = 0;
    virtual ~IRadioStrategy()
    {
        
    }
    
protected:
    char*                           m_url;
    scoped_ptr<CDataReceiver>       m_dataRcvr;
    scoped_ptr<audio::CAudioOut>    m_audioOut;
    u32                             m_inPort;

};

} // namespace eradio

#endif	/* IRADIOSTRATEGY_HPP */

