/*******************************************************************
* https://leetcode.com/problems/arranging-coins/
* Easy
* 
* Conception: 
*  1. 
*
* You have a total of n coins that you want to form in a staircase shape,
* where every k-th row must have exactly k coins.
*
* Given n, find the total number of full staircase rows that can be formed.
* n is a non-negative integer and fits within the range of a 32-bit signed integer.
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
    int arrangeCoins(int n) {
        int total = 0;
        while(n >= 0){
            total++;
            n -= total;
        }
        if( n != 0){
            return (total - 1);
        }
        return total;
    }
};