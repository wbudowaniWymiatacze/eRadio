/* 
 * File:   shared_array.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 8:06 PM
 */

#ifndef SHARED_ARRAY_HPP
#define	SHARED_ARRAY_HPP

#include <algorithm>
#include <map>

namespace boost
{

typedef unsigned int u32;

template <typename T>
class shared_array
{

public:
    explicit shared_array(T* arr = 0) :
        m_arr(arr)
    {
        m_referencesCounter     = new u32;
        *m_referencesCounter    = 1;
    }
    
    shared_array(shared_array<T>& sharedArrayObj);
    
    shared_array<T>& operator=(shared_array<T>&);
    
    shared_array<T>& operator=(T* );
    
    void reset(T* newArr = 0);
    
    T& operator[](u32 idx)
    {
        return m_arr[idx];
    }
    
    // returns pointer to the held array
    T* get()
    {
        return m_arr;
    }

	// shares references counter so that it may be changed by another shared_ptr
	u32* shareRefCounter()
    {
        return m_referencesCounter;
    }
    
    void swap(shared_array<T>& newSharedArray);
    
    ~shared_array()
    {
        unwrap();
    }
        
private:
	// unwraps currently wrapped object
	void unwrap();
    
    T*      m_arr;
    u32*    m_referencesCounter;
};

template<typename T>
shared_array<T>::shared_array(shared_array<T>& sharedArrayObj)
{
    // copy construct is called for new objects only
    // no need to unwrap this object
    
    m_arr               = sharedArrayObj.get();
    m_referencesCounter = sharedArrayObj.shareRefCounter();
    (*m_referencesCounter)++;
}
    
template<typename T>
shared_array<T>& shared_array<T>::operator=(shared_array<T>& sharedArrayObj)
{
    unwrap();
    
    m_arr               = sharedArrayObj.get();
    m_referencesCounter = sharedArrayObj.shareRefCounter();
    (*m_referencesCounter)++;
    
    return *this;
}
    
template<typename T>
shared_array<T>& shared_array<T>::operator=(T* arr)
{
    unwrap();
    
    m_arr                   = arr;
    m_referencesCounter     = new u32;
    *m_referencesCounter    = 1;
    
    return *this;
}

template<typename T>
void shared_array<T>::reset(T* newArr)
{
    if(newArr != m_arr)
    {
        // unwrap currently held array
        unwrap();

        m_arr = newArr;
        m_referencesCounter = new u32;
        *m_referencesCounter = 1;
    }
}

template<typename T>
void shared_array<T>::swap(shared_array<T>& newSharedArray)
{
    std::swap(*this,
              newSharedArray);
}

template<typename T>
void shared_array<T>::unwrap()
{
    if(--(*m_referencesCounter) == 0)
    {
        if(m_arr != 0)
        {
            delete[] m_arr;
            delete m_referencesCounter;
            m_arr               = 0;
            m_referencesCounter = 0;
        }
    }
}

}


#endif	/* SHARED_ARRAY_HPP */

