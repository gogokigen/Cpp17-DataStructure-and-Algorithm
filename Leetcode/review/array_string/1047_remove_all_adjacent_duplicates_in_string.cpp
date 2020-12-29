/*******************************************************************
* https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
* Easy
* 
* Conception: 
*  1.
*
* Given a string S of lowercase letters,
* a duplicate removal consists of choosing two adjacent and equal letters,
* and removing them.
*
* We repeatedly make duplicate removals on S until we no longer can.
* Return the final string after all such duplicate removals have been made.
* It is guaranteed the answer is unique.
*
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    string removeDuplicates(string S) {
        int stptr = -1;
         for(int i = 0; i < S.size(); i++) {
            if(stptr == -1 || S[i] != S[stptr]) {
                stptr++;
                S[stptr] = S[i];
            }
            else {
                stptr--;
            }
        }

        string ans = "";
        for(int i = 0; i <= stptr; i++) {
            ans.push_back(S[i]);
        }
        return ans;
    }
};
