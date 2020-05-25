/*******************************************************************
* https://leetcode.com/problems/uncrossed-lines/
* Medium
* 
* Conception: 
*  1. 
*
* We write the integers of A and B (in the order they are given) on two separate horizontal lines.
*
* Example:
* Input: A = [1,4,2], B = [1,2,4]
* Output: 2
* Explanation: We can draw 2 uncrossed lines as in the diagram.
* We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int aLen = A.size();
        int bLen = B.size();
        vector<vector<int>> dp(aLen + 1, vector<int> (bLen+1));
        for(int i = 1; i <= aLen; i++){
            for(int j = 1; j <= bLen; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[aLen][bLen];

    }
};