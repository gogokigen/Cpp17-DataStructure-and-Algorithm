/*******************************************************************
* https://leetcode.com/problems/string-compression/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of characters, compress it in-place.
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. 
*******************************************************************/
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        for(int j = 1, count = 1; j <= chars.size(); j++, count++) {
            if(j == chars.size() || chars[j] != chars[j - 1]) {
                chars[i] = chars[j - 1];
                i++;//for the position of chars[i]
                if(count >= 2){
                    for(char digit : to_string(count)) {
                        chars[i] = digit;
                        i++;//for the position of count
                    }
                }
                count = 0;
            }
        }
        return i;
    }
};