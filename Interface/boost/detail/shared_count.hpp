/* 
 * File:   shared_count.hpp
 * Author: artur
 *
 * Created on December 26, 2012, 2:09 PM
 */

#ifndef SHARED_COUNT_HPP
#define	SHARED_COUNT_HPP

namespace boost
{

typedef unsigned int    u32;

class shared_count
{
public:
    shared_count()
    {
        m_count     = new u32;
        *m_count    = 1;
    }
    
    /**
     * stores the input argument's counter address in m_counter and increases
     * the count
     * @param other shared counter which m_counter will be shared with
     *                       this
     */
    shared_count(const shared_count& other)
    {
        // called only for new objects creation. No need to unwrap
        m_count = other.m_count;
        ++(*m_count);
    }
    
    /**
     * unwraps currently stored count and stores the input argument's counter
     * address in m_counter and increases the count
     * @param other shared counter which m_counter will be shared with
     *                       this
     * @return this with increased count
     */
    shared_count& operator=(const shared_count& other)
    {
        unwrap();

        m_count = other.m_count;
        ++(*m_count);

        return *this;
    }
    
    /**
     * Prefix decrement operator. Decreases number of counts
     * @return shared_count with decreased number of count
     */
    shared_count& operator--()
    {
        (*m_count)--;
        return *this;
    }
    
    /**
     * Postfix decrement operator. Decreases number of counts
     * @return shared_count with decreased number of count
     */
    shared_count& operator--(int)
    {
        (*m_count)--;
        return *this;
    }
    
    /**
     * Returns the count number
     * @return count number
     */
    u32 use_count() const
    {
        return *m_count;
    }
    
    /**
     * swaps addresses pointed by counters
     * @param other shared_count to swap the pointers with
     */
    void swap(shared_count& other)
    {
        std::swap(m_count, other.m_count);
    }
    
    /**
     * Resets count number to 1
     */
    void reset()
    {
        *m_count = 1;
    }
    
    /**
     * calls unwrap()
     */
    ~shared_count()
    {
        unwrap();
    }
    
private:
    /**
     * decreases count number and if counter == 0 deletes it
     */
    void unwrap()
    {
        if(*m_count == 0)
        {
            delete m_count;
            m_count = 0;
        }
    }
    
    u32* m_count;
};

}   // namespace boost

#endif	/* SHARED_COUNT_HPP */

