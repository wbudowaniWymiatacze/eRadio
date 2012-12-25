/* 
 * File:   CAudioHw.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 9:41 PM
 */

#ifndef CAUDIOHW_HPP
#define	CAUDIOHW_HPP

#include <gloDefs.hpp>

namespace eradio
{
namespace audio
{

class IAudioHwState;

class CAudioHw
{
public:
    
    CAudioHw();

    void Configure()
    {
        
    }
    
    void Play(const u32* const  buffer,
              const u32         length) const
    {
        (void) buffer;
        (void) length;
    }
    
    void Deconfigure()
    {
        
    }
    
    virtual ~CAudioHw();
private:
    IAudioHwState* m_hwState;
};

} // namespace audio
} // namespace eradio

#endif	/* CAUDIOHW_HPP */

