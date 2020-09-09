/*******************************************************************
* https://leetcode.com/problems/moving-average-from-data-stream/
* Easy
* 
* Conception: 
*  1. 
*
* Given a stream of integers and a window size,
* calculate the moving average of all integers in the sliding window.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.  
*
*******************************************************************/
class MovingAverage 
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) 
    {
        m_max_capacity = size;
        m_cur_size = 0;
        m_sum = 0;
        m_window = new int[m_max_capacity];
    }

    double next(int val) 
    {        
        if(m_cur_size == m_max_capacity)
        {
            --m_cur_size;
            m_sum -= *m_window;

            for(int i =1; i < m_max_capacity; ++i)
            {
                m_window[i -1] = m_window[i];
            }
        }

        m_sum += val;
        m_window[m_cur_size] = val;

        ++m_cur_size;

        double average = (double)(m_sum / m_cur_size);
        return average;
    }

private:
    double m_sum;
    int m_cur_size;
    int m_max_capacity;
    int* m_window;
};


/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */