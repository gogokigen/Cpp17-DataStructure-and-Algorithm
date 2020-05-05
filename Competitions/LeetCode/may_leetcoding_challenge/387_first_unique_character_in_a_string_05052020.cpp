/*******************************************************************
* https://leetcode.com/problems/first-unique-character-in-a-string/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string, find the first non-repeating character in it and return it's index.
* If it doesn't exist, return -1. 
*
* Example:
*
* Hints:
*  1. ARSCII: 265
*  2. <time, last time appear position>
*
* Ref:
*  1. 
*
* Advanced:
*
*******************************************************************/


class Solution {
public:
    int firstUniqChar(string str) {
        if(str.length() == 0) return -1;
        pair<char,int> tbl[256];
        for(int i = 0; i < str.length(); i++){
            tbl[str[i]].first++;
            tbl[str[i]].second = i;
        }
        int ret = INT_MAX;
        for(int i = 0; i < 256; i++){
            if(tbl[i].first == 1){
                ret = min(ret , tbl[i].second);
            }
        }
        
        if(ret == INT_MAX) return -1;
        
        return ret;
    }
};