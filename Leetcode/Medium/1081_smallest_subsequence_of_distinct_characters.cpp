/*******************************************************************
* https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
* Medium
* 
* Conception: 
*  1.
*
* Return the lexicographically smallest subsequence of text that
* contains all the distinct characters of text exactly once.
*
*
* Example:
* 
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
    string smallestSubsequence(string text) {
        int n = text.length();
        
        unordered_map<char, int> table;
        for (int i = 0; i < n; i++)
            table[text[i]]++;
        
        unordered_map<char, bool>seen;
        string res;
        
        for (int i = 0; i < n; i++) {
            table[text[i]]--;
            if (seen[text[i]]) continue;
            seen[text[i]] = true;
            
            while(!res.empty() && res.back() > text[i] && table[res.back()] > 0) {
                seen[res.back()] = false;
                res.pop_back();
            }
            
            res.push_back(text[i]);
        }
        
        return res;
    }
};