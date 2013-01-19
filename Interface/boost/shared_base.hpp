/* 
 * File:   shared_base.hpp
 * Author: artur
 *
 * Created on January 19, 2013, 1:00 PM
 */

#ifndef SHARED_BASE_HPP
#define	SHARED_BASE_HPP

#include <algorithm>    // std::swap
#include <boost/detail/shared_count.hpp>

namespace boost
{

typedef unsigned int u32;

template < typename T >
class shared_base
{
public:

    // creates shared_base with object to point to
    explicit shared_base(T* obj = 0) :
        m_ptr(obj),
        m_counter()
    {
    }

    // copy constructor
    shared_base(shared_base< T >& other) :
        m_ptr(other.get()),
        m_counter(other.m_counter)
    {
        /*
         * unwrap not needed cause copy constructor is called
         * for not existing objects
         */
    }
    
    T* get() const
    {
        return m_ptr;
    }
    
    u32 use_count() const
    {
        return m_counter.use_count();
    }

    void reset(T* newPtr = 0)
    {
        if(newPtr != m_ptr)
        {
            unwrap();

            m_ptr = newPtr;
            m_counter.reset();
        }
    }

    shared_base< T >& operator=(const shared_base< T >& other)
    {
        // unwrap the currently wrapped object
        unwrap();

        m_ptr       = other.get();
        m_counter   = other.m_counter;

        return *this;
    }

    virtual ~shared_base()
    {
        // derived class is responsible for freeing resources
    }
    
protected:
    // to be defined by a derived class
    virtual void unwrap() = 0;
    
    T*              m_ptr;
    shared_count    m_counter;
};

}   // namespace boost

#endif	/* SHARED_BASE_HPP */

