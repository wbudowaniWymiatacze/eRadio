/* 
 * File:   IDataReceiverState.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 10:03 PM
 */

#ifndef IDATARECEIVERSTATE_HPP
#define	IDATARECEIVERSTATE_HPP

#include <gloDefs.hpp>

namespace eradio
{

class IDataReceiverState
{
public:
    IDataReceiverState(u32* inOutBuffer) :
        m_inOutBuffer(inOutBuffer)
    {
        
    }
        
    virtual ~IDataReceiverState()
    {
        
    }
        
protected:
    virtual void Receive(const u32* const   data,
                         const u32          length) const = 0;
    u32*    m_inOutBuffer;
};

} // namespace eradio


#endif	/* IDATARECEIVERSTATE_HPP */

