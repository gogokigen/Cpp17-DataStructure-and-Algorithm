/*******************************************************************
* https://leetcode.com/problems/longest-common-subsequence/
* Medium
* 
* Conception: 
*  1. 
*
* Given two strings text1 and text2, return the length of their longest common subsequence.
* A subsequence of a string is a new string generated from the original string 
* with some characters(can be none) deleted without changing the relative order of the remaining characters.
* (e.g., "ace" is a subsequence of "abcde" while "aec" is not).
* A common subsequence of two strings is a subsequence that is common to both strings.
*
* Example:
*
* Key:
*  1. continuous is not necessary
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int lenText1 = text1.size();
        int lenText2 = text2.size();
        vector<vector<int>> dp( lenText1+1 , vector<int> (lenText2+1, 0));

        for(int i = 1; i < lenText1+1; ++i){
            for(int j = 1; j < lenText2+1; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[lenText1][lenText2];
    }
};