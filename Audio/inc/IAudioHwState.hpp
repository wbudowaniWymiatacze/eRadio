/* 
 * File:   IAudioHwState.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 9:46 PM
 */

#ifndef IAUDIOHWSTATE_HPP
#define	IAUDIOHWSTATE_HPP

#include <gloDefs.hpp>

namespace eradio
{
namespace audio
{

class IAudioHwState
{
protected:
    virtual void Configure()        = 0;
    virtual void Play(u32*  data,
                      u32   length) = 0;
    virtual void Deconfigure()      = 0;    
};

} // namespace audio
} // namespace eradio

#endif	/* IAUDIOHWSTATE_HPP */

