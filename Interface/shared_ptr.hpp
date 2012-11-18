/* 
 * File:   shared_ptr.hpp
 * Author: artur
 *
 * Created on November 10, 2012, 7:43 PM
 */

#ifndef SHARED_PTR_HPP
#define	SHARED_PTR_HPP

#include <cassert>

namespace boostmod
{

typedef unsigned int u32;

template < typename T >
class shared_ptr
{
public:

	// creates shared_ptr with object to point to
	explicit shared_ptr( T* obj = 0 ) :
        m_obj( obj )
	{
		m_referencesCounter = new u32;
		*m_referencesCounter = ( u32 ) 1;
	}

	// copy constructor
	shared_ptr( shared_ptr< T >& sharedPtrObj );
    
    void reset(T* newArr);

	// dereference will point to the wrapped object
	// shared_ptr->foo() will call m_obj->foo()
	T* operator->() const
    {
        assert( m_obj != 0 );
        return m_obj;
    }
    
    T operator*() const
    {
        return *m_obj;
    }

	// current object is "unwrapped", its reference value is decreased
	// wraps object wrapped by the argument, gets its references counter and increases it
	shared_ptr< T >& operator=(shared_ptr< T >& );

	// current object is "unwrapped", its reference value is decreased
	// wraps the argument object, increases references counter
	shared_ptr< T >& operator=( T* );
        
	// returns pointer to the wrapped object
	T* get() const
    {
        return m_obj;
    }

	// shares references counter so that it may be changed by another shared_ptr
	u32* shareRefCounter() const
    {
        return m_referencesCounter;
    }
    
    // returns the number of shared_ptr objects referring to the same managed object
    u32 use_count() const
    {
        return *m_referencesCounter;
    }
    
    void swap(shared_ptr<T>& sharedPtrObj);

	~shared_ptr();

protected:

	// unwraps currently wrapped object
	void unwrap();

	T*		m_obj;
	u32*	m_referencesCounter;
};

template < typename T >
shared_ptr< T >::shared_ptr( shared_ptr< T >& sharedPtrObj )
{
    /*
     *  unwrap not needed cause copy constructor is called
     * for not existing objects
     */
    m_obj = sharedPtrObj.getObj();
    m_referencesCounter = sharedPtrObj.shareRefCounter();
    ( *m_referencesCounter )++;
}

template < typename T >
void shared_ptr< T >::reset(T* newArr)
{
    unwrap();
    
    m_obj                   = newArr;
    m_referencesCounter     = new u32;
    *m_referencesCounter    = 1;
}

template < typename T >
shared_ptr< T >& shared_ptr< T >::operator=( const shared_ptr< T >& sharedPtrObj )
{
    // unwrap the currently wrapped object
    unwrap();

    m_obj = sharedPtrObj.getObj();
    m_referencesCounter = sharedPtrObj.shareRefCounter();
    *( m_referencesCounter )++;

    return *this;
}

template < typename T >
shared_ptr< T >& shared_ptr< T >::operator=( const T* obj )
{
    // unwrap the currently wrapped object
    unwrap();

    m_obj                   = obj;
    m_referencesCounter     = new u32;
    *m_referencesCounter    = 1;

    return *this;
}

template < typename T >
void shared_ptr< T >::unwrap()
{
    if ( --( *m_referencesCounter ) == 0 )
    {
        if ( m_obj != 0 )
        {
            delete m_obj;
            delete m_referencesCounter;
        }
    }
}

template < typename T >
shared_ptr< T >::~shared_ptr()
{
    unwrap();
}

}

#endif	/* SHARED_PTR_HPP */

