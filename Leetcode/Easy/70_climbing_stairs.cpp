/*******************************************************************
* https://leetcode.com/problems/climbing-stairs/
* Easy
* 
* Conception: 
*  1. Fibonacci eries
*
* You are climbing a stair case. It takes n steps to reach to the top.
* Each time you can either climb 1 or 2 steps.
* In how many distinct ways can you climb to the top?
* Note: Given n will be a positive integer.
*
*
* Example:
*
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
    int climbStairs(int n) {
        if (n == 0){
            return 0;
        } else if (n == 1){
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            vector<int> dp(n,0);
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; i++){
                dp[i] = dp[i-2] + dp[i-1];
            }
            return dp[n-1] ;
        }
    }
};