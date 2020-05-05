/*******************************************************************
* https://leetcode.com/problems/longest-common-prefix/
* Easy
* 
* Conception: 
*  1. 
*
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.geeksforgeeks.org/longest-common-prefix-using-character-by-character-matching/
*
*******************************************************************/
class Solution {
private:
    int findMinLength(vector<string>& strs){
        int min = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].length() < min){
                min = strs[i].length();
            }
        }
        return min;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int minLen = findMinLength(strs);
        
        string ret;
        for(int i = 0; i < minLen; i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i]){
                    return ret;
                }
            }
            ret = ret + strs[0][i];
        }
        return ret;
    }
};