/*******************************************************************
* https://leetcode.com/problems/sqrtx/
* Easy
* 
* Conception: 
*  1. 
*
* Given a non-negative integer x,
* compute and return the square root of x.
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int mySqrt(int x) {
        if( x == 0) return 0;
        if ( x == 1) return 1;
        long l = 1;
        long r = x / 2;
        if( l * l == x) return l;
        if(r * r == x ) return r;
        
        while(l <= r) {
            int m = l + (r - l) /2;
            if( (long) m * m == x){
                return m;
            } else if ( (long) m * m < x){
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};