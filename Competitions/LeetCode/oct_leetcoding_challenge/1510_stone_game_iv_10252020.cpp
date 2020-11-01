/*******************************************************************
* https://leetcode.com/problems/stone-game-iv/
* Hard
* 
* Conception: 
*  1. 
*
* Alice and Bob take turns playing a game, with Alice starting first.
* Initially, there are n stones in a pile.
* On each player's turn,
* that player makes a move consisting of removing any non-zero square number of stones in the pile.
*
* Also, if a player cannot make a move, he/she loses the game.
* Given a positive integer n. Return True if and only if 
* Alice wins the game otherwise return False, assuming both players play optimally.
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
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[0] = false;

        for (int i=1; i<dp.size(); i++) {
            int temp = sqrt(i);
            if (temp * temp == i) {
                dp[i] = true;
            } else {
                for (int j=1; j*j<i; j++) {
                    if (!dp[i - (j*j)]) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};