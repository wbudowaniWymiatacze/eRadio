/* 
 * File:   CAudioDecoder.hpp
 * Author: artur
 *
 * Created on November 7, 2012, 10:34 PM
 */

#ifndef IAUDIODECODERSTRATEGY_HPP
#define	IAUDIODECODERSTRATEGY_HPP

#include <IAudioDecoder.hpp>
#include <DecoderTypes.hpp>

namespace eradio
{
namespace audio
{

// forward-declare template to be able to specialize only certain types
template <typename decType>
class CAudioDecoder;

template<>
class CAudioDecoder<SOggDecoder> : public IAudioDecoder
{
public:
    CAudioDecoder()
    {
        
    }
    
    CAudioDecoder(const CAudioDecoder& orig);
    void Decode() const
    {
        
    }
    
    virtual ~CAudioDecoder()
    {
        
    }
private:

};

} // namespace audio
} // namespace eradio

#endif	/* IAUDIODECODERSTRATEGY_HPP */

