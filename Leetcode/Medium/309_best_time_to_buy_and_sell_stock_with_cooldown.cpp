/*******************************************************************
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
* Medium
* 
* Conception: 
*  1. 
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
* Design an algorithm to find the maximum profit.
* You may complete as many transactions as you like
* (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
*
*    You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*    After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/932932/c%2B%2Bor-easy-to-understand-or-explainable-ordescribe-in-Chinese
*
*******************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];     
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1; i <= n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            if (i == 1){
                dp[i][1] = max( dp[i-1][1], dp[i-1][0] - prices[i-1]);// first day
            }else{
                dp[i][1] = max( dp[i-1][1], dp[i-2][0] - prices[i-1]);
            }
        }
        return max( dp[n][0], dp[n][1]);
    }
};