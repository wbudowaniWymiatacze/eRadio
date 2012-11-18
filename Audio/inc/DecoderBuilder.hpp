/* 
 * File:   DecoderBuilder.hpp
 * Author: artur
 *
 * Created on November 17, 2012, 10:46 PM
 */

#ifndef DECODERBUILDER_HPP
#define	DECODERBUILDER_HPP

#include <IAudioDecoder.hpp>
#include <CAudioDecoder.hpp>
#include <DecoderTypes.hpp>

namespace eradio
{
namespace audio
{

IAudioDecoder* BuildDecoder(const char* decType)
{
    (void) decType;
//    switch(decType)
//    {
//        case "ogg":
            return (IAudioDecoder*) new CAudioDecoder<SOggDecoder>;
//            break;
//    }
}

}
}

#endif	/* DECODERBUILDER_HPP */

