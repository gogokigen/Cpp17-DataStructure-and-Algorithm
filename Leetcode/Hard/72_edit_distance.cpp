/*******************************************************************
* https://leetcode.com/problems/edit-distance/
* Hard
* 
* Conception: 
*  1. 
*
* Given two words word1 and word2,
* find the minimum number of operations required to convert word1 to word2.
*
* You have the following 3 operations permitted on a word:
*
*    Insert a character
*    Delete a character
*    Replace a character
*
*
* Key:
*
*
* Explanation:
*
* References:
*  1. https://www.geeksforgeeks.org/edit-distance-dp-5/
*
*******************************************************************/
class Solution {
private:
    int min(int x, int y, int z) { 
        return ::min( ::min(x, y), z); 
    } 
  
    int helper(string str1, string str2, int m, int n) { 
        vector<vector<int>> dp(m+1, vector<int> (n+1));

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if (i == 0){
                    dp[i][j] = j; 
                }else if (j == 0) {
                    dp[i][j] = i; 
                }else if (str1[i - 1] == str2[j - 1]){
                    dp[i][j] =  dp[i - 1][j - 1]; 
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
                                       dp[i - 1][j], // Remove 
                                       dp[i - 1][j - 1]); // Replace 
                }
            }
        }
        return dp[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        return helper(word1, word2, word1.length(), word2. length());
    }
};

