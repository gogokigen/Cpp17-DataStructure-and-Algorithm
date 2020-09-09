/*******************************************************************
* https://leetcode.com/problems/word-pattern/
* Easy
* 
* Conception: 
*  1. 
*
* Given a pattern and a string str, find if str follows the same pattern.
*
* Here follow means a full match,
* such that there is a bijection between a letter in pattern and a non-empty word in str.
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
public:
    bool wordPattern(string pattern, string str){
        unordered_map<char, string> letterToWordMap;
        unordered_set<string> wordsTaken;

        istringstream iss(str);
        string token;

        int i = 0;

        while(iss >> token){
            if(auto it = letterToWordMap.find(pattern[i]); it != letterToWordMap.end()){
                if(it->second != token){
                    return false;
                }
            } else {
                if(wordsTaken.find(token) != wordsTaken.end()){
                    return false;
                }

                letterToWordMap[pattern[i]] = token;
                wordsTaken.insert(token);
            }

            ++i;
        }

        return i == pattern.size();
    }
};