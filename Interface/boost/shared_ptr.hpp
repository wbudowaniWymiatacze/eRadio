/* 
 * File:   shared_ptr.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 7:43 PM
 */

#ifndef SHARED_PTR_HPP
#define	SHARED_PTR_HPP

#include <algorithm>    // std::swap
#include <boost/detail/shared_count.hpp>

namespace boost
{

typedef unsigned int u32;

template < typename T >
class shared_ptr
{
public:

    // creates shared_ptr with object to point to
    explicit shared_ptr(T* obj = 0) :
        m_ptr(obj),
        m_counter()
    {
    }

    // copy constructor
    shared_ptr(shared_ptr< T >& sharedPtrObj) :
        m_ptr(sharedPtrObj.get()),
        m_counter(sharedPtrObj.m_counter)
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
    
    T* operator->() const
    {
        return m_ptr;
    }

    shared_ptr< T >& operator=(const shared_ptr< T >& sharedPtrObj)
    {
        // unwrap the currently wrapped object
        unwrap();

        m_ptr       = sharedPtrObj.get();
        m_counter   = sharedPtrObj.m_counter;

        return *this;
    }

    void swap(shared_ptr<T>& sharedPtrObj)
    {
        std::swap(*this, sharedPtrObj);
    }

    ~shared_ptr()
    {
        unwrap();
    }

protected:

    // unwraps currently wrapped object
    void unwrap()
    {
        if((--m_counter).use_count() == 0)
        {
            if(m_ptr != 0)
            {
                delete m_ptr;
                m_ptr = 0;
            }
        }
    }

    T*              m_ptr;
    shared_count    m_counter;
};

}   // namespace boost

#endif	/* SHARED_PTR_HPP */

