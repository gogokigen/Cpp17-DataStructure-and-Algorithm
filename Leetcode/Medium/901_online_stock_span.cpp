/*******************************************************************
* https://leetcode.com/problems/online-stock-span/
* Medium
* 
* Conception: 
*  1. 
*
* Write a class StockSpanner which collects daily price quotes for some stock,
* and returns the span of that stock's price for the current day.
*
* The span of the stock's price today is
* defined as the maximum number of consecutive days (starting from today and going backwards)
* for which the price of the stock was less than or equal to today's price.
*
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. https://www.youtube.com/watch?v=RGRC46zHB98&t=435s
*
*******************************************************************/
class StockSpanner {
private:
    vector<int> dp;
    vector<int> prices;
    int pos = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if( pos == 0 || price < prices.back()){
            dp.push_back(1);
        }else{
            int j = pos - 1;
            while(j >= 0 && price >= prices[j]){
                j -= dp[j];
            }
            dp.push_back(pos - j);
        }
        pos++;
        prices.push_back(price);
        return dp.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */