/*******************************************************************
* https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string s and an integer k, return the length of the longest substring of s
* such that the frequency of each character in this substring is greater than or equal to k.
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
    int getMaxUniqueLetters( string s) {
        bool map[26] = {false};
        int maxUnique = 0;
        for(int i = 0; i < s.length(); i++){
            if(!map[s[i] - 'a']){
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        return maxUnique;
    }
public:
    int longestSubstring(string s, int k) {
        vector<int> countMap(26, 0);
        int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            fill(countMap.begin(), countMap.end(), 0);

            int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
            while (windowEnd < s.size()) {
                
                if(unique <= currUnique){
                    idx = s[windowEnd] - 'a';
                    if (countMap[idx] == 0) unique++;
                    countMap[idx]++;
                    if (countMap[idx] == k) countAtLeastK++;
                    windowEnd++;
                } else {
                    idx = s[windowStart] - 'a';
                    if (countMap[idx] == k) countAtLeastK--;
                    countMap[idx]--;
                    if (countMap[idx] == 0) unique--;
                    windowStart++;
                }
                if (unique == currUnique && unique == countAtLeastK)
                    result = max(windowEnd - windowStart, result);
            }
            
        }
        
        return result;
    }
};
