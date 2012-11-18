/* 
 * File:   CShoutcastStrategy.cpp
 * Author: artur
 * 
 * Created on November 7, 2012, 9:38 PM
 */

#include <CShoutcastStrategy.hpp>
#include <CHttpClient.hpp>

namespace eradio
{

CShoutcastStrategy::CShoutcastStrategy(CHttpClient& http,
                                       const char* url) :
    IRadioStrategy(url),
    m_http(http)
{
    
}
    
CShoutcastStrategy::~CShoutcastStrategy()
{

}

} // namespace eradio

