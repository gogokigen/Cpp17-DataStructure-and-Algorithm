/*******************************************************************
* https://leetcode.com/problems/group-anagrams/
* Medium
* 
* Conception: 
*  1. set
*  2. sorting char
*
* Given an array of strings, group anagrams together.
*
*
* Example:
* Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
* Output:
* [
*   ["ate","eat","tea"],
*   ["nat","tan"],
*   ["bat"]
* ]
*
* Key:
*  1. 
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> table;
        for (auto str: strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            table[strCopy].push_back(str);
        }
        //["aet":"ate","eat","tea"],
        vector<vector<string>> ret;
        for(auto i:table){
            ret.push_back(i.second);
        }
        return ret;
    }
};