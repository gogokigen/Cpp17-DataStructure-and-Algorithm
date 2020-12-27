/*******************************************************************
* https://leetcode.com/problems/generate-parentheses/
* Medium
* 
* Conception: 
*  1. 
*
* Given n pairs of parentheses,
* write a function to generate all combinations of well-formed parentheses.
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
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,n,"",ans);
        return ans;
    }
    
    void helper(int l, int r, string out, vector<string>& ans){
        if ( l < 0 || r < 0 || l > r) return;
        if (l == 0 && r == 0) {
            ans.push_back(out);//legal == add
            return;
        }
        helper( l -1, r, out + "(", ans); // if last left is more than right, left - 1 and add "(" to ans.
        helper( l, r -1, out + ")", ans);
    }
};