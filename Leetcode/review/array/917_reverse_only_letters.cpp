/*******************************************************************
* https://leetcode.com/problems/reverse-only-letters/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string S, return the "reversed" string 
* where all characters that are not a letter stay in the same place,
* and all letters reverse their positions.
*
* Example:
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/
class Solution {
public:
    string reverseOnlyLetters(string S) {
        if(S.empty()) return "";
        
        for(int left = 0, right = S.length()-1; left < right; left++, right--){
            while(left < right && !isalpha(S[left])){
                left++; //ignore !(a~z||A~Z||0~9)
            }
            while(left < right && !isalpha(S[right])){
                right--; //ignore !(a~z||A~Z||0~9)
            }
            
            char tmp = S[left];
            S[left] = S[right];
            S[right] = tmp;
        }
        return S;
    }
};
