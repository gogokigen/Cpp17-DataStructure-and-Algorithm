/*******************************************************************
* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
* Easy
* 
* Conception: 
*  1. 
*
* Say you have an array for which the ith element is the price of a given stock on day i.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int i = 0 ; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }else if (prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};