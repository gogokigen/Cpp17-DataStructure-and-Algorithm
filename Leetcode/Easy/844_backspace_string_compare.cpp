/*******************************************************************
* https://leetcode.com/problems/backspace-string-compare/
* Easy
* 
* Conception: 
*  1. string, erase
*
* Given two strings S and T, return 
* if they are equal when both are typed into empty text editors.
* # means a backspace character.
*
*
* Example:
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
    void removeIcon(string& S) {
        int pos = S.find("#");
        while(pos != -1){
            if(pos == 0){ // S[0] == "#"
                S = S.substr(1);
            }else{
                S = S.erase(pos - 1, 2);
            }
            pos = S.find("#");
        }
    }
    bool backspaceCompare(string S, string T) {
        if (S == T) return true;
        removeIcon(S);
        removeIcon(T);
        return S == T;
    }
};