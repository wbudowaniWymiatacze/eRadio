/* 
 * File:   CFileStrategy.cpp
 * Author: artur
 * 
 * Created on November 9, 2012, 11:57 PM
 */
#include <iostream>
#include <stdio.h>  // for char
#include <string.h> // for strchr()

#include <boost/shared_array.hpp>
#include <boost/scoped_ptr.hpp>

#include <CFileStrategy.hpp>
#include <CTcpServer.hpp>
#include <CDataReceiver.hpp>
#include <CAudioOut.hpp>
#include <CAudioDecoder.hpp>
#include <DecoderBuilder.hpp>

namespace eradio
{

CFileStrategy::CFileStrategy(tcp::CTcpServer& tcpServer,
                             const char* url) :
    IRadioStrategy(url),
    m_file(new std::ifstream(url))    // open with input mode by default for ifstream
{
    // create audio buffer for storing data from Tcp/Ip
    // and reading by audio output object
    const u32 audioBufLen   = AUDIO_BUFFER_SIZE/sizeof(u32);
    ::boost::shared_array<u32> audioBuffer(new u32[audioBufLen]);
    m_dataRcvr.reset(new CDataReceiver(tcpServer,
                                       audioBuffer,
                                       audioBufLen));
    
    // create decoder based on the file extension
    // find last '.' in the string. File extension is after the '.'
    const char* dotPtr                  = strrchr(url, '.') + 1;
    char decType[4];
    strcpy(decType, dotPtr);
    audio::IAudioDecoder* audioDecoder  = audio::BuildDecoder(decType);
    audio::CAudioHw* audioHw            = new audio::CAudioHw;
    
    m_audioOut.reset(new audio::CAudioOut(audioDecoder,
                                          audioHw,
                                          audioBuffer,
                                          audioBufLen));
    
}

void CFileStrategy::Play()
{
    using namespace std;
    
    m_audioOut->Execute();
    cout<<"playing"<<endl;
}

void CFileStrategy::Pause()
{
    using namespace std;
    
    cout<<"pause"<<endl;
}

void CFileStrategy::Stop()
{
    using namespace std;
    
    cout<<"stop"<<endl;
}

CFileStrategy::~CFileStrategy()
{
}

} // namespace eradio

