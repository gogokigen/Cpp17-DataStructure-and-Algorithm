/*******************************************************************
* https://leetcode.com/problems/bitwise-and-of-numbers-range/
* Medium
* 
* Conception: 
*  1. 
*
* Given a range [m, n] where 0 <= m <= n <= 2147483647,
* return the bitwise AND of all numbers in this range, inclusive.
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://www.geeksforgeeks.org/bitwise-and-or-of-a-range
*
*******************************************************************/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while( m < n){
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};