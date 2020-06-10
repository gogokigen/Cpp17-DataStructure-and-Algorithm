/*******************************************************************
* https://leetcode.com/problems/hamming-distance/
* Easy
* 
* Conception: 
*  1. 
*
* The Hamming distance between two integers is the number of positions
* at which the corresponding bits are different.
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
    int hammingDistance(int x, int y) {
        x = x^y;
        int ret = 0;
        while(x){
            if(x % 2 == 1){
                ret++;
            }
            x>>=1;
        }
        return ret;
    }
};