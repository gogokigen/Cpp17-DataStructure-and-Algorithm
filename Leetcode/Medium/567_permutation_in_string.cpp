/*******************************************************************
* https://leetcode.com/problems/permutation-in-string/
* Medium
* 
* Conception: 
*  1. 
*
* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
* In other words, one of the first string's permutations is the substring of the second string.
*
*
* Key:
*  1. Sliding Window with Array -> #438
*
*******************************************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Len = s1.length(), s2Len = s2.length();
        if(s1Len > s2Len) return false;
        vector<int> s1Tbl(26,0);
        vector<int> s2Tbl(26,0);
        for(char i:s1){
            s1Tbl[i-'a']++;
        }

        for(int i = 0; i < s2Len; i++){
            s2Tbl[(int)s2[i]-'a']++;
            if(i >= s1Len){
                s2Tbl[(int)s2[i-s1Len]-'a']--;
            }
            if(s1Tbl==s2Tbl){
                return true;
            }
        }
        return false;
    }
};