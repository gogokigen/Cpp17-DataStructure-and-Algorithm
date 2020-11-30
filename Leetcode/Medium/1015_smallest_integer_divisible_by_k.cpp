/*******************************************************************
* https://leetcode.com/problems/smallest-integer-divisible-by-k/
* Medium
* 
* Conception: 
*  1. 
*
* Given a positive integer K,
* you need to find the length of the smallest positive integer N such that
* N is divisible by K, and N only contains the digit 1.
*
* Return the length of N. If there is no such N, return -1.
* Note: N may not fit in a 64-bit signed integer.
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
class Solution {
public:
    //here the logic is to store the remainder of number instead of number itself
    // K=7
    // 0 * 10 + 1 = 1 % 7 = 1
    // 1 * 10 + 1 = 11% 7 = 4
    // 4 * 10 + 1 = 41 % 7 = 
    
    
    // and to detect whether its present or not loop until the remainder starts coming again
    //as remainder can only be in range 0 to K-1
    //so when it starts repeating you its in loop and return -1
    //here Length can only be less than or equal to K
    int smallestRepunitDivByK(int K) {
        int NLength=0;
        int remainder=0;
        
        for(NLength=1;NLength<=K;NLength++)
        {
            remainder = ((remainder * 10) +1)%K;
            if(remainder==0)
                return NLength;
            
        }
        return -1;
    }
};
