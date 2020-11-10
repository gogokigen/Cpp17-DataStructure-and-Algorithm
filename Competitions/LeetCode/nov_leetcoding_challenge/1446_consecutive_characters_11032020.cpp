/*******************************************************************
* https://leetcode.com/problems/consecutive-characters/
* Easy
* 
* Conception: 
*  1. 
*
* Given a string s,
* the power of the string is the maximum length of a non-empty substring that
* contains only one unique character.
* Return the power of the string.
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
    int maxPower(string s) {
        int i = 0, n = s.length() - 1, ans = 1, c = 0;
        while(i < n){
            c = 1;
            while(s[i]==s[i+1]){
                c++,i++; //count how many are same
            }
            ans=max(ans,c); //max check
            i++;
        }
        return ans;
    }
};