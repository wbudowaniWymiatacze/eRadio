/* 
 * File:   shared_array.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 8:06 PM
 */

#ifndef SHARED_ARRAY_HPP
#define	SHARED_ARRAY_HPP

#include <algorithm>
#include <boost/shared_base.hpp>

namespace boost
{

typedef unsigned int u32;

template <typename T>
class shared_array : public shared_base<T>
{

public:
    explicit shared_array(T* arr = 0) :
        shared_base<T>(arr)
    {
    }
    
    shared_array(shared_array<T>& other) :
        shared_base<T>(other)
    {
        
    }

    void swap(shared_array<T>& other)
    {
        std::swap(*this, other);
    }
    
    T& operator[](u32 idx)
    {
        return shared_base<T>::m_ptr[idx];
    }
    
    virtual ~shared_array()
    {
        unwrap();
    }
        
private:
	// unwraps currently wrapped object
	void unwrap()
    {
        if((--shared_base<T>::m_counter).use_count() == 0)
        {
            if(shared_base<T>::m_ptr != 0)
            {
                delete[] shared_base<T>::m_ptr;
                shared_base<T>::m_ptr = 0;
            }
        }
    }
};

}


#endif	/* SHARED_ARRAY_HPP */

