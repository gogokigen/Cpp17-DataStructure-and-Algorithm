/*******************************************************************
* https://leetcode.com/problems/number-of-1-bits/
* Easy
* 
* Conception: 
*  1. 
*
* Write a function that takes an unsigned integer and return the number of '1' bits it has
* (also known as the Hamming weight).
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
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(n & 1){
                ans++;
            }
            n >>= 1;
        }
        return ans;
    }
};