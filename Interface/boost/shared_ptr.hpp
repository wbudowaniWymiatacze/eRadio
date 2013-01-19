/* 
 * File:   shared_ptr.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 7:43 PM
 */

#ifndef SHARED_PTR_HPP
#define	SHARED_PTR_HPP

#include <algorithm>    // std::swap
#include <boost/shared_base.hpp>

namespace boost
{

typedef unsigned int u32;

template < typename T >
class shared_ptr : public shared_base<T>
{
public:

    // creates shared_ptr with object to point to
    explicit shared_ptr(T* obj = 0) :
        shared_base<T>(obj)
    {
    }

    // copy constructor
    shared_ptr(shared_ptr< T >& other) :
        shared_base<T>(other)
    {
        /*
         * unwrap not needed cause copy constructor is called
         * for not existing objects
         */
    }

    void swap(shared_ptr<T>& other)
    {
        std::swap(*this, other);
    }
    
    T* operator->() const
    {
        return shared_base<T>::m_ptr;
    }

    virtual ~shared_ptr()
    {
        unwrap();
    }

private:

    // unwraps currently wrapped object
    virtual void unwrap()
    {
        if((--shared_base<T>::m_counter).use_count() == 0)
        {
            if(shared_base<T>::m_ptr != 0)
            {
                delete shared_base<T>::m_ptr;
                shared_base<T>::m_ptr = 0;
            }
        }
    }
};

}   // namespace boost

#endif	/* SHARED_PTR_HPP */

