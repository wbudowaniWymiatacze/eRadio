/* 
 * File:   CAudioOut.hpp
 * Author: artur
 *
 * Created on November 7, 2012, 10:31 PM
 */

#ifndef CAUDIOOUT_HPP
#define	CAUDIOOUT_HPP

#include <gloDefs.hpp>

#include <scoped_ptr.hpp>
#include <shared_array.hpp>
#include <SCircBuffer.hpp>
#include <IAudioDecoder.hpp>
#include <CAudioHw.hpp>

namespace eradio
{
namespace audio
{

// będzie dziedziczyć po TimerListner jeżeli trigger przez Timer
class CAudioOut
{
public:
    CAudioOut(IAudioDecoder*                decoder,
              CAudioHw*                     audioHw,
              ::boostmod::shared_array<u32> audioBuffer,
              u32                           bufLen);
    void Execute();
    virtual ~CAudioOut();
private:
    SCircBuffer<audioBufT>                  m_audioBuffer;
    ::boostmod::scoped_ptr<IAudioDecoder>   m_decoder;
    ::boostmod::scoped_ptr<CAudioHw>        m_audioHw;
};

} // namespace audio
} // namespace eradio

#endif	/* CAUDIOOUT_HPP */

