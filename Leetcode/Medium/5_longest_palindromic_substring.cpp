/*******************************************************************
* https://leetcode.com/problems/longest-palindromic-substring/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string s, find the longest palindromic substring in s.
* You may assume that the maximum length of s is 1000.
*
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/articles/longest-palindromic-substring/
*
*******************************************************************/
//Expand Around Center
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();

        if( len==0) return "";
        
        int subSize = 0;
        int left = 0;
        int right = 0;
        int start = -1;
        for(int i = 0; i < 2*len; i++){
            left = i/2;
            right = i/2 + i % 2;
            while( left >= 0 && right <= len && s[left] == s[right]){
                if(subSize < (right - left + 1)){
                    // found larger substring, so update subSize =  right - left + 1
                    subSize = (right - left + 1);
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, subSize);
    }
};

//dp
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if( len==0) return "";
        vector<vector<int>> dp(len, vector<int> (len, 0));
        // dp[i][j] means s[i, j] is palindrome or not 
        string ret;
        for(int j = 0; j < len; j++){
            for(int i = j; i >= 0; i--){
                if(s[i] != s[j]){
                    dp[i][j] = 0;
                }else{
                    if( j - i<= 1){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    
                    if(dp[i][j] && ret.size() < j - i + 1){
                        ret = s.substr( i , j - i + 1);
                    }
                }
            }
        }
        return ret;
    }
};