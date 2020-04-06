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

        multiset<string> category;
        unordered_map <string,vector<string>> table;
        for (auto str: strs) {
            string strCopy = str;
            sort(strCopy.begin(), strCopy.end());
            table[strCopy].push_back(str);
        }
        //for(auto i:strs){
        //    table[strSort(i)].push_back(i);
        //}

        vector<vector<string>> ret;
        for(auto i:table){
            ret.push_back(i.second);
        }
        return ret;
    }
private:
    string strSort(string s) {
        int n = s.size(), counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};