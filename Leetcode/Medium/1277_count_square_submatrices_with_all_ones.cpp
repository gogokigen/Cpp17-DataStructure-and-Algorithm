/*******************************************************************
* https://leetcode.com/problems/count-square-submatrices-with-all-ones/
* Medium
* 
* Conception: 
*  1. 
*
* Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*
*
* Key:
*  1. 
*
* Explanation:
*
* matrix =
* [
*  [0,1,1,1],
*  [1,1,1,1],
*  [0,1,1,1]
* ]
*
* dp =
* [
*  [0,1,1,1],
*  [1,1,2,2],
*  [0,1,2,3]
* ]

* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int l = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(l, vector<int>(c));
        int ret = 0;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                dp[i][j] = matrix[i][j];
                if(i && j && dp[i][j]){
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                }
                ret += dp[i][j];
            }
        }
        return ret;
    }
};