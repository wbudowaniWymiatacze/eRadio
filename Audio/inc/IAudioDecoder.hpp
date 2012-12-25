/* 
 * File:   IAudioDecoder.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 9:08 PM
 */

#ifndef IAUDIODECODER_HPP
#define	IAUDIODECODER_HPP
#include <iostream>

namespace eradio
{
namespace audio
{

/*
 * This class is only to show the interface that different audio decoders
 * should have and to be able to have 1 member field for different decoder types.
 * That's why there's no virtual function.
 */
class IAudioDecoder
{
public:
    virtual void Decode() const
    {
        using namespace std;
        cout<<"IAudioDecoder::Decode"<<endl;
    }
    
    virtual ~IAudioDecoder()
    {
        
    }
};

} // namespace audio
} // namespace eradio

#endif	/* IAUDIODECODER_HPP */

