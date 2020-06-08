/*******************************************************************
* https://leetcode.com/problems/power-of-two/
* Easy
* 
* Conception: 
*  1. 
*
* Given an integer, write a function to determine if it is a power of two.
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
    bool isPowerOfTwo(int n) {
        if( n == 0) return false;
        long x = (long)n;
        return (x&(x-1)) == 0;
    }
};