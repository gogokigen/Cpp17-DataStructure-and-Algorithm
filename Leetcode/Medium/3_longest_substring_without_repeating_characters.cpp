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
*  1. window slice
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
        set<char> table;
        int left = 0, right = 0;
        
        int ret = 0;
        
        while(left < s.length() && right < s.length()){
            if(table.find(s[right]) == table.end()){
                table.insert(s[right]);
                right++;
                ret = max(ret, right - left);
            } else {
                table.erase(s[left]);
                left++;
            }
        }
        return ret;
    }
};