/*******************************************************************
* https://leetcode.com/problems/cheapest-flights-within-k-stops/
* Medium
* 
* Conception: 
*  1. Minimal Path of Graph
*
* There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
*
* Now given all the cities and flights, together with starting city src and the destination dst,
* your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
*
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. https://www.youtube.com/watch?v=PLY-lbcxEjg
*
*******************************************************************/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int maxCost = 1e9;
        vector<vector<int>> dp(K + 2, vector<int> (n , maxCost)); //dp: K+2 * n
        dp[0][src] = 0;
        for(int i = 1; i < K + 2; i++){
            dp[i][src] = 0;
            for(auto& f:flights){
                dp[i][f[1]] = min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]);
            }
        }
        return dp[K+1][dst] >= maxCost ? -1 : dp[K+1][dst];                
    }
};