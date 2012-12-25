/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on November 15, 2012, 10:02 PM
 */

#include <CTcpServer.hpp>
#include <IRadioStrategy.hpp>
#include <CFileStrategy.hpp>
#include <COggContainer.hpp>
#include <iostream>
#include <iosfwd>
#include <cstring>

using namespace eradio;

/*
 * 
 */
int main(int argc, char** argv)
{
    tcp::CTcpServer tcpServer;
    const char* url = "http://olsztyn.radio.pionier.net.pl:8000/z/radioram.ogg";
    IRadioStrategy* radioStrat = (IRadioStrategy*) new CFileStrategy(tcpServer,
                                                                     url);
    
    radioStrat->Play();
    radioStrat->Pause();
    radioStrat->Stop();
    
    std::ifstream file("/home/artur/Music/Pincode (disc 2_ PiN Party)/06. Gone.ogg");
    COggContainer ogg(file);
    
    u8 data[7];
    ogg.GetPayload(data,
                   7);
    
    char str[] = "aaaaaa";
    memcpy(str, &data[1], 6);
    std::cout<<"type = "<<data[0]<<" string = "<<str<<std::endl;
    
    return 0;
}

