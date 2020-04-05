/*******************************************************************
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
* Easy
* 
* Conception: 
*  1. 
*
* Say you have an array for which the ith element is the price of a given stock on day i.
* Design an algorithm to find the maximum profit.
* You may complete as many transactions as you like
* (i.e., buy one and sell one share of the stock multiple times).
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
    int maxProfit(vector<int>& prices ){
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++){
            if (prices[i - 1] < prices[i]){
                max_profit += prices[i] - prices[i-1];
            }
        }
        return max_profit;
    }
};