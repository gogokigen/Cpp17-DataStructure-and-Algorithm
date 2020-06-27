/*******************************************************************
* https://leetcode.com/problems/perfect-squares/
* Medium
* 
* Conception: 
*  1. 
*
* Given a positive integer n, find the least number of perfect square numbers
* (for example, 1, 4, 9, 16, ...) which sum to n.
*
*
* Example:
*
* Key:
*  1.
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        int maxSquare = (int)sqrt(n) + 1;
        vector<int> squareList(maxSquare, 0);
        for(int i = 1; i < maxSquare; i++){
            squareList[i] = i*i;
        }

        for (int i = 1; i <= n; i++) {
            for (int s = 1; s < maxSquare; s++) {
                if (i < squareList[s]){
                    break;
                }
                dp[i] = min(dp[i], dp[i - squareList[s]] + 1);
            }
        }
        return dp[n];
    }
};