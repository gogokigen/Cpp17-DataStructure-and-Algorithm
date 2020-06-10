/*******************************************************************
* https://leetcode.com/problems/reverse-bits/
* Easy
* 
* Conception: 
*  1. 
*
* Reverse bits of a given 32 bits unsigned integer.
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
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 31;
        while (n != 0) {
            ret += (n & 1) << power;
            n >>= 1;
            power--;
        }
        return ret;
    }
};