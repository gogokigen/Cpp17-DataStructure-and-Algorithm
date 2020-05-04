/*******************************************************************
* https://leetcode.com/problems/powx-n/
* Medium
* 
* Conception: 
*  1. 
*
* Implement pow(x, n), which calculates x raised to the power n (xn).
*
* Example:
*
* Notes:
*  1. Avoid "%"
*  2. notice negative numbers
*
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/
class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0) return 1.0;
        double res = myPow(x, n/2);

        if( n&1 && n >= 0 ){
            return res * res * x;
        } else if( n&1 && n<0 ){
            return res * res * 1/x;
        }else {
            return res * res;
        }
    }
};