/*******************************************************************
* https://leetcode.com/problems/valid-perfect-square/
* Easy
* 
* Conception: 
*  1. 
*
* Given a positive integer num, write a function
* which returns True if num is a perfect square else False.
*
* Key:
*  1. 
*
* Reference:
*  1. https://medium.com/@lenchen/leetcode-367-valid-perfect-square-bd0211741d81
*
*******************************************************************/
// Binary search
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <2) return true;
        long l = 1;
        long r = num/2;
        long m = l + (r - l)/2;

        while(l <= r){
            m = l + (long)(r - l)/2.0;
            if( m * m == num){
                return true;
            }else if ( m * m > num){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return m * m == (long)num;
    }
};

// Newton's method
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <2) return true;
        long ret = (long)num/2.0;
        while (ret*ret > num){
            ret = (ret + (((long)num)/(long)ret))/2.0;
        }
        return ret * ret == (long)num;
    }
};