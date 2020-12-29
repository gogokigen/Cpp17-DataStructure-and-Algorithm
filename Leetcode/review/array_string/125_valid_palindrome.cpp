/*******************************************************************
* https://leetcode.com/problems/valid-palindrome/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string, determine if it is a palindrome,
* considering only alphanumeric characters and ignoring cases.
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
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        
        for(int left = 0, right = s.length()-1; left < right; left++, right--){
            while(left < right && !isalnum(s[left])){
                left++; //ignore !(a~z||A~Z||0~9)
            }
            while(left < right && !isalnum(s[right])){
                right--; //ignore !(a~z||A~Z||0~9)
            }
            
            if( left < right && tolower(s[left]) != tolower(s[right])){ 
                //ignoring cases.
                return false;
            }
        }

        return true;
    }
};