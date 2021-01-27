/*******************************************************************
* https://leetcode.com/problems/knight-probability-in-chessboard/
* Medium
* 
* Conception: 
*  1. 
*
* On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves.
* The rows and columns are 0 indexed, so the top-left square is (0, 0),
* and the bottom-right square is (N-1, N-1).
*
* A chess knight has 8 possible moves it can make, as illustrated below.
* Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
*
*
* Key:
*  1.
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>>dp;
public:
    double knightProbability(int N, int K, int r, int c) {
        if(dp.count(r) && dp[r].count(c) && dp[r][c].count(K)) return dp[r][c][K];
        if(r < 0 || r >= N || c < 0 || c >= N) return 0;
        if(K == 0) return 1;
        double total = knightProbability(N, K - 1, r - 1, c - 2) + knightProbability(N, K - 1, r - 2, c - 1) 
                     + knightProbability(N, K - 1, r - 1, c + 2) + knightProbability(N, K - 1, r - 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c + 2) + knightProbability(N, K - 1, r + 2, c + 1) 
                     + knightProbability(N, K - 1, r + 1, c - 2) + knightProbability(N, K - 1, r + 2, c - 1);
        double res = total / 8;
        dp[r][c][K] = res;
        return res;
    }
};