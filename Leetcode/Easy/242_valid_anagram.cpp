/*******************************************************************
* https://leetcode.com/problems/valid-anagram/
* Easy
* 
* Conception: 
*  1. 
*
* Given two strings s and t , write a function to determine if t is an anagram of s.
*
*
* Example:
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
    bool isAnagram(string s, string t) {
        if(s.length() == 0&& t.length() == 0) return true;
        if(s.length() != t.length()) return false;
        
        vector<int> tbl(26,0);
        for(int i = 0; i < s.length(); i++){
            tbl[s[i]-'a']++;
            tbl[t[i]-'a']--;
        }
        
        for(auto i:tbl){
            if(i != 0) return false;
        }
        return true;
    }
};