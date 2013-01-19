/* 
 * File:   scoped_ptr.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 10:41 PM
 */

#ifndef SCOPED_PTR_HPP
#define	SCOPED_PTR_HPP

#include <algorithm>

namespace boost
{

template<typename T>
class scoped_ptr
{
public:
    scoped_ptr(T* obj = 0) :
        m_ptr(obj)
    {

    }
        
    /*
     * copy constructor and operator= are trivial
     */
        
    void reset(T* obj = 0)
    {
        delete m_ptr;
        m_ptr = obj;
    }

    T operator*() const
    {
        return *m_ptr;
    }

    T* operator->() const
    {
        return m_ptr;
    }

    T* get() const
    {
        return m_ptr;
    }

    void swap(scoped_ptr<T>& other)
    {
        std::swap(*this, other);
    }
    
    ~scoped_ptr()
    {
        delete m_ptr;
        m_ptr = 0;
    }
        
private:
    T* m_ptr;
};

} // namespace boostmod

#endif	/* SCOPED_PTR_HPP */

