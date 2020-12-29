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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();

        unordered_map<char, int> mp; // {char , start pos}
        int start = 0, ans = 0;

        for(int end = 0; end < len; end++){
            
            // if s[end] can be found in mp, then update start position
            if(mp.find(s[end]) != mp.end()&& mp[s[end]] >= start){
                start = mp[s[end]] + 1;
            }
            mp[s[end]] = end;
            ans = max( ans, end - start + 1);
        }
        return ans;
    }
};
