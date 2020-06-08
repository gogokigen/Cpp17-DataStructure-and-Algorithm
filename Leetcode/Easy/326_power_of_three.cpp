/*******************************************************************
* https://leetcode.com/problems/power-of-three/
* Easy
* 
* Conception: 
*  1. 
*
* Given an integer, write a function to determine if it is a power of three.
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
    // Math
    bool isPowerOfThree(int n) {
        
        return fmod((log10(n)/log10(3)),1) == 0;
    }
    // loop
    bool isPowerOfThree(int n) {
        if( n == 0) return false;
        
        while( n % 3 == 0){
            n /= 3;
        }
        
        return n == 1;
    }
};