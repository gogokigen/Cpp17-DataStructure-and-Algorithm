/*******************************************************************
* https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string s , find the length of the longest substring t 
* that contains at most 2 distinct characters.
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int max_len = 0;
        int len = s.size();
        if (len <= 2) return len;
        int l = 0, r = 1;
        // get first two distinct substring
        while(s[r] == s[l] && r < len){
            r++;
        }
        if (r == len){
            return len;
        }
        int left = s[l], right = s[r];
        while(r < len){
            // try to see when third value appears
            while (s[r] == left || s[r] == right){
                r++;
            }
            // cout << l << r-1 << endl;
            max_len = max(max_len, r-l);
            l = r-1;
            while (s[l] == s[r-1]){
                l--;
            }
            l++;
            left = s[l];
            right = s[r];
        }
        return max_len;
    }
};
