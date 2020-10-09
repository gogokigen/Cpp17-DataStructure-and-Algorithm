/*******************************************************************
* https://leetcode.com/problems/word-squares/
* Hard
* 
* Conception: 
*  1. 
*
* Given a set of words (without duplicates), find all word squares you can build from them.
*
* A sequence of words forms a valid word square if the kth row and column read the exact same string,
* where 0 ≤ k < max(numRows, numColumns).
*
* For example, the word sequence ["ball","area","lead","lady"] forms a word square
* because each word reads the same both horizontally and vertically.
*
* b a l l
* a r e a
* l e a d
* l a d y
*
* Note:
*    There are at least 1 and at most 1000 words.
*    All words will have the exact same length.
*    Word length is at least 1 and at most 5.
*    Each word contains only lowercase English alphabet a-z.
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
    unordered_map<string,vector<string>> prefixMap;
    vector<vector<string>> wordSquares(vector<string>& words) {
        storePrefixWords(words);
        vector<vector<string>> result;
        
        for(auto word: words){
            vector<string> ls;
            ls.push_back(word);
            backTrack(1,ls,result);
        }
        return result;
    }
    
    void backTrack(int level, vector<string> &ls, vector<vector<string>> &result){
        if(level==ls[0].size()){
            result.push_back(ls);
            return;
        }
        string prefix = "";
        for(auto word: ls){
            prefix = prefix + word[level];
        }
        
        vector<string> pfxwords;
        pfxwords = prefixMap[prefix];
        for(auto word: pfxwords){
            ls.push_back(word);
            backTrack(level+1,ls,result);
            ls.pop_back();
        }
    }
    void storePrefixWords(vector<string> words){
        for(auto word:words){
            for(int i=1;i<=word.size();i++){
                string prefix = word.substr(0,i);
                prefixMap[prefix].push_back(word);
            }
        }
    }
};