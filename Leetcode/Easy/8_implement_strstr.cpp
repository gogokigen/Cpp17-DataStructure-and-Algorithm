/*******************************************************************
* https://leetcode.com/problems/implement-strstr/
* Easy
* 
* Conception: 
*  1. 
*
* Implement strStr().
*
* Return the index of the first occurrence of needle in haystack,
* or -1 if needle is not part of haystack.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0 ) return 0;
        if( haystack.size()==0 )    return -1;
        
        int h_length = haystack.size();
        int n_length = needle.size();
        if( n_length > h_length ) return -1;
        
        for(int i = 0; i <= h_length - n_length; i++){
            if(needle == haystack.substr(i, n_length)){
                return i;
            }
        }
        return -1;
    }
};