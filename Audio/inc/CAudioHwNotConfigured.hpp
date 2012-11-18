/* 
 * File:   CAudioHwNotConfigured.hpp
 * Author: artur
 *
 * Created on November 9, 2012, 9:46 PM
 */

#ifndef CAUDIOHWNOTCONFIGURED_HPP
#define	CAUDIOHWNOTCONFIGURED_HPP

#include <IAudioHwState.hpp>

namespace eradio
{
namespace audio
{

class CAudioHwNotConfigured : public IAudioHwState
{
public:
    CAudioHwNotConfigured();
    
    virtual void Configure();
    virtual void Play(u32*  data,
                      u32   length);
    virtual void Deconfigure(); 
    virtual ~CAudioHwNotConfigured();
private:

};

} // namespace audio
} // namespace eradio

#endif	/* CAUDIOHWNOTCONFIGURED_HPP */

