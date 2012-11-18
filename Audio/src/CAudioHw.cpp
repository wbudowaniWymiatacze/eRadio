/* 
 * File:   CAudioHw.cpp
 * Author: artur
 * 
 * Created on November 9, 2012, 9:41 PM
 */

#include <CAudioHw.hpp>
#include <CAudioHwNotConfigured.hpp>

namespace eradio
{
namespace audio
{

CAudioHw::CAudioHw() :
    m_hwState(new CAudioHwNotConfigured)
{
}

CAudioHw::~CAudioHw()
{
}

} // namespace audio
} // namespace eradio

