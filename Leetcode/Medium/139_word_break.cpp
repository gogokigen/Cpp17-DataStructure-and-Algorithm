/*******************************************************************
* https://leetcode.com/problems/word-break/
* Medium
* 
* Conception: 
*  1. dp
*
*
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
* determine if s can be segmented into a space-separated sequence of one or more dictionary words.
*
*
* Example:

* 
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0 || s.empty()) return false;
        int n = s.length();
        
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) { //fix the s.legth
            for(auto k : wordDict){ // find in dictionary
                int startIdx = i - k.size(); //start index of substring
                if(startIdx < 0 || dp[startIdx] == false) continue;
                if ( k == s.substr(startIdx, k.size())){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};