/*******************************************************************
* https://leetcode.com/problems/longest-substring-without-repeating-characters/
* Medium
* 
* Conception: 
*  1. set
*
* Given a string, find the length of the longest substring without repeating characters.
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
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> tbl;
        int i = 0, j = 0;
        int ret = 0;
        while( i < s.length() && j < s.length()){
            if(tbl.find(s[i]) == tbl.end()){
                tbl.insert(s[i]);
                i++;
                ret = max(ret, i - j);
            }else{
                tbl.erase(s[j]);
                j++;
            }
        }
        return ret;
    }
};