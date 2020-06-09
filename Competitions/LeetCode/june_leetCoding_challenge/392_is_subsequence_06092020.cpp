/*******************************************************************
* https://leetcode.com/problems/is-subsequence/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string s and a string t, check if s is subsequence of t.
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
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        if(t=="") return false;
        int s_ptr = 0;
        for(int t_ptr = 0; t_ptr < t.length(); t_ptr++){
            if(s_ptr < s.length() && s[s_ptr] == t[t_ptr]){
                if(s_ptr == s.length() - 1){
                    return true;
                }else{
                    s_ptr++;
                }
            }
        }
        return false;
    }
};