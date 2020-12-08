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
//BFS
class Solution {
public:
    int numSquares(int n) {
        int count = 1, itr = 0, target = 0;
        unordered_set<int> visited;
        visited.insert(0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int itr = q.front();
                q.pop();
                for(int i = 1; i*i <= n; i++){
                    target = itr + i * i;
                    if(target  == n){
                        return count;
                    }

                    if( target < n && !visited.count(target)){
                        q.push(target);
                        visited.insert(target);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
//DP
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
