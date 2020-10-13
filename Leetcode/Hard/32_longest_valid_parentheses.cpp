/*******************************************************************
* https://leetcode.com/problems/longest-valid-parentheses/
* Hard
* 
* Conception: 
*  1. 
*
* Given a string containing just the characters '(' and ')',
* find the length of the longest valid (well-formed) parentheses substring.
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
    int longestValidParentheses(string s) {
        vector<int> dp(s.size()+1,0);
        stack<int> sp;
        int ans = 0;
        for(int i = 1; i <= s.size(); i++){
            if(s[i-1]==')'){

                if(sp.empty()){
                    dp[i] = 0;
                } else {
                    dp[i] = dp[sp.top()-1] + 2 + dp[i-1];
                    sp.pop();
                }
            }else {
                sp.push(i);
                dp[i] = 0;
            }
            ans = max(ans,dp[i]);
        }
        
        return ans;
    }
};