/*******************************************************************
* https://leetcode.com/problems/reverse-words-in-a-string/
* Medium
* 
* Conception: 
*  1. 
*
* Given an input string s, reverse the order of the words.
* A word is defined as a sequence of non-space characters.
* The words in s will be separated by at least one space.
*
* Return a string of the words in reverse order concatenated by a single space.
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
    string reverseWords(string s) {
        if(s.length() == 0) return "";

        int len = s.length();

        vector<string> table;
        string tmp = "";
        for(int i = 0; i < len; i++){
            if(s[i] == ' '){
                if(tmp.length() != 0){
                    table.push_back(tmp);
                    tmp = "";
                }
            } else {
                tmp += s[i];
            }
        }
        
        table.push_back(tmp);

        string revString;
        for(int i = table.size() - 1; i > 0; i--){
            if(table[i].length() != 0){
                revString += table[i] + " ";
            }
        }
        
        
        return table[0].length() == 0? revString: (revString + table[0]);
    }
};