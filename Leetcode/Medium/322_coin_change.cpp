/*******************************************************************
* https://leetcode.com/problems/coin-change/
* Medium
* 
* Conception: 
*  1. 
*
* You are given coins of different denominations and a total amount of money amount.
* Write a function to compute the fewest number of coins that you need to make up that amount.
* If that amount of money cannot be made up by any combination of the coins, return -1.
*
*
* Example:
* 
* Key:
*  1. 
*
* References:
*  1. https://medium.com/@ryanyang1221/leetcode-challenge-coin-change-2-6-7-70d9f1c3c06d
*
*******************************************************************/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for(int i = 1; i < amount + 1; i++){
            for(int c:coins){
                if( i >= c){
                    dp[i] = min( dp[i], dp[ i - c] + 1);
                }
            }
        }
        
        if(dp[amount] <= amount) return dp[amount];
        return -1;
    }
};