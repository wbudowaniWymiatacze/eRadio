/* 
 * File:   CAudioOut.cpp
 * Author: artur
 * 
 * Created on November 7, 2012, 10:31 PM
 */

#include <shared_array.hpp>

#include <CAudioOut.hpp>

namespace eradio
{
namespace audio
{

CAudioOut::CAudioOut(IAudioDecoder*                 decoder,
                     CAudioHw*                      audioHw,
                     ::boostmod::shared_array<u32>  audioBuffer,
                     u32                            bufLen) :
    m_audioBuffer(audioBuffer, bufLen),
    m_decoder(decoder),
    m_audioHw(audioHw)
{
}

CAudioOut::~CAudioOut()
{
}

} // namespace eradio
} // namespace audio

