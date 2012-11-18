/* 
 * File:   main.cpp
 * Author: artur
 *
 * Created on November 15, 2012, 10:02 PM
 */

#include <CTcpServer.hpp>
#include <IRadioStrategy.hpp>
#include <CFileStrategy.hpp>

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
    return 0;
}

