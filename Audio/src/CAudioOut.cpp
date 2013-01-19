/* 
 * File:   CAudioOut.cpp
 * Author: artur
 * 
 * Created on November 7, 2012, 10:31 PM
 */

#include <boost/scoped_ptr.hpp>
#include <boost/shared_array.hpp>

#include <CAudioOut.hpp>

namespace eradio
{
namespace audio
{

CAudioOut::CAudioOut(IAudioDecoder*                 decoder,
                     CAudioHw*                      audioHw,
                     ::boost::shared_array<u32>  audioBuffer,
                     u32                            bufLen) :
    m_audioBuffer(audioBuffer.get(), bufLen),
    m_decoder(decoder),
    m_audioHw(audioHw)
{
}

void CAudioOut::Execute()
{
    m_decoder->Decode();
}

CAudioOut::~CAudioOut()
{
}

} // namespace audio
} // namespace eradio

