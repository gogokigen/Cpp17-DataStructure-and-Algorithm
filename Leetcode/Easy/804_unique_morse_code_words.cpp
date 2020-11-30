/*******************************************************************
* https://leetcode.com/problems/unique-morse-code-words/
* Easy
* 
* Conception: 
*  1. 
*
* ...
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
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set <string> rez;
        for(int i=0;i < words.size();i++){
            string s="";
            for(int j =0; j<words[i].size();j++)
                s += morse[words[i][j] - 'a'];
            rez.insert(s);
        }
        return rez.size();
    }
};
