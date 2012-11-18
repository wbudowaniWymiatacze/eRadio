/* 
 * File:   CShoutcastStrategy.hpp
 * Author: artur
 *
 * Created on November 7, 2012, 9:38 PM
 */

#ifndef CSHOUTCASTSTRATEGY_HPP
#define	CSHOUTCASTSTRATEGY_HPP

#include <IRadioStrategy.hpp>

namespace eradio
{

class CHttpClient;

class CShoutcastStrategy : public IRadioStrategy
{
public:
    CShoutcastStrategy(CHttpClient& http,
                       const char* url);    
    virtual ~CShoutcastStrategy();
    
private:
    CHttpClient& m_http;
};

}

#endif	/* CSHOUTCASTSTRATEGY_HPP */

