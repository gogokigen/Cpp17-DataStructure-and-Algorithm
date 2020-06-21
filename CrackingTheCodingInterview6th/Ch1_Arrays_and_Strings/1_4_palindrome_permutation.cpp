/*******************************************************************
* https://leetcode.com/problems/palindrome-permutation/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string, determine if a permutation of the string could form a palindrome.
*
*
* Example:
*
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
    bool canPermutePalindrome(string s) {
        vector<int> tbl(128, 0);
        for(char i:s ){
            if(tbl[i] == 1){
                tbl[i] -= 1;
            } else if(tbl[i] == 0){
                tbl[i] += 1;
            } else {
                return false;
            }
        }
        int count = 0;
        for(int i = 0; i < 128; i++){
            count += tbl[i];
        }
        
        return count > 1 ? false:true;
    }
};