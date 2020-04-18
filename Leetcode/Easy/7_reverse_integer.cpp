/*******************************************************************
* https://leetcode.com/problems/reverse-integer/
* Easy
* 
* Conception: 
*  1. 
*
* Given a 32-bit signed integer, reverse digits of an integer.
*
* Example:
*
* Ref:
*  1. Notice: overflow!! https://www.cnblogs.com/grandyang/p/4125588.html
*
* Advanced:
*  1. Reverse Bits
*  2. String to Integer (atoi)
*
*******************************************************************/
class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while (x != 0) {
            res = 10 * res + x % 10;
            x /= 10;
        }
        return (res > INT_MAX || res < INT_MIN) ? 0 : res;
    }
};