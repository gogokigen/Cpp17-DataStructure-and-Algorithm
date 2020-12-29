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
//window slicing
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxLength = 0, windowStart = 0;
        unordered_map<char, int> table;
        
        int len = s.length();

        for(int windowEnd = 0; windowEnd < len; windowEnd++) {
          table[s[windowEnd]]++;

          // table.size() > 2 表示有超過 2 個 distinct character
          while(table.size() > 2) {
            if(--table[s[windowStart]] == 0)
              table.erase(s[windowStart]);

            windowStart++;
          }

          // 經過上面的 while 迴圈處理，這時 window 必定滿足條件
          maxLength = max(maxLength, windowEnd-windowStart+1);
        }

        return maxLength;
    }
};


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
