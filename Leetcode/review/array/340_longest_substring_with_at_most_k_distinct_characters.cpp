/*******************************************************************
* https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string s and an integer k,
* return the length of the longest substring of s that
* contains at most k distinct characters.
*
*
* Example:
*
* Key:
*  1. window slicing
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLength = 0, windowStart = 0;
        unordered_map<char, int> table;
        
        int len = s.length();

        for(int windowEnd = 0; windowEnd < len; windowEnd++) {
          table[s[windowEnd]]++;

          // table.size() > k 表示有超過 k 個 distinct character
          while(table.size() > k) {
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
