/*******************************************************************
* https://leetcode.com/problems/length-of-last-word/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
* return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
*
* If the last word does not exist, return 0.
* Note: A word is defined as a maximal substring consisting of non-space characters only.
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
    int lengthOfLastWord(string s) {
        istringstream ss(s); string word; 
        while (ss) ss >> word; 
        return word.length();
    }
};