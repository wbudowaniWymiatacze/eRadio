/* 
 * File:   gloDefs.hpp
 * Author: artur
 *
 * Created on November 6, 2012, 9:45 PM
 */

#ifndef GLODEFS_HPP
#define	GLODEFS_HPP

#include <types.hpp>
#include <shared_array.hpp>

/*
 * audio buffer size in bytes
 * Should be enough to hold 5s MP3 data at 192 KB/s bitrate
 */
#define AUDIO_BUFFER_SIZE   150000

namespace eradio
{
// type of buffer for audio data
typedef u32 audioBufT;

} // namespace eradio

#endif	/* GLODEFS_HPP */

