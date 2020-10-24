/*******************************************************************
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
* Notice that you may not engage in multiple transactions simultaneously
* (i.e., you must sell the stock before you buy again).
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/900061/C++-DP-based-General-Solution-20-Time-~10-Space
*
*******************************************************************/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        // edge cases away
        if (!k || len < 2) return 0;
 
        // fixing k to be a meaningful, even number
        k = min(k * 2, len - len % 2);

        // declaring and setting up dp
        int dp[k];

        for (int i = 0; i < k; i++) dp[i] = i % 2 ? 0 : INT_MAX;

        for (int currPrice: prices) {
            // setting up the first dp element
            dp[0] = min(dp[0], currPrice);

            // updating dp with all the subsequent trades
            for (int i = 1; i < k; i++) {
                dp[i] = i % 2 ? max(dp[i], currPrice - dp[i - 1]) : min(dp[i], currPrice - dp[i - 1]);
            }
        }
        return dp[k - 1];
    }
};