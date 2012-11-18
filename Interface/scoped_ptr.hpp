/* 
 * File:   scoped_ptr.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 10:41 PM
 */

#ifndef SCOPED_PTR_HPP
#define	SCOPED_PTR_HPP

#include <algorithm>

namespace boostmod
{

template<typename T>
class scoped_ptr
{
public:
    scoped_ptr(T* obj = 0) :
        m_obj(obj)
    {

    }
        
    /*
     * copy constructor and operator= are trivial
     */
        
    void reset(T* obj = 0)
    {
        delete m_obj;
        m_obj = obj;
    }

    T operator*() const
    {
        return *m_obj;
    }

    T* operator->() const
    {
        return m_obj;
    }

    T* get() const
    {
        return m_obj;
    }

    void swap(scoped_ptr<T>& scopedPtrObj)
    {
        scoped_ptr<T>& tmp = *this;
        std::swap< scoped_ptr<T> >(tmp, scopedPtrObj);
        *this = tmp;
    }
    
    ~scoped_ptr()
    {
        delete m_obj;
    }
        
private:
    T* m_obj;
};

} // namespace boostmod

#endif	/* SCOPED_PTR_HPP */

