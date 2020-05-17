/*******************************************************************
* https://leetcode.com/problems/find-all-anagrams-in-a-string/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
*
*
* Key:
*  1. Sliding Window with Array
*
* Explanation:
*  pLen = 3, sLen = 10, p ="abc"
*
*                i,   a b c d e, i-pLen+1 
*  "cbaebabacd"  2    1 1 1    , 0         V
*      ^         3,   1 1 1   1
*   x                 1 1     1, 1
*       ^        4,   1 2     1
*    x            ,   1 1     1, 2
*        ^       5,   2 1     1
*     x           ,   1 1     1, 3
*         ^      6,   1 2     1
*      x          ,   1 2     0, 4
*          ^     7,   2 2     0
*       x         ,   2 1     0, 5
*           ^    8,   2 1 1   0
*        x        ,   1 1 1   0, 6         V

*******************************************************************/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        if(sLen < pLen) return {};
        vector<int> sTbl(26,0);
        vector<int> pTbl(26,0);
        for(char i:p){
            pTbl[i-'a']++;
        }

        vector<int> ret;
        for(int i = 0; i < sLen; i++){
            sTbl[(int)s[i]-'a']++;
            if(i >= pLen){
                sTbl[(int)s[i-pLen]-'a']--;
            }
            if(sTbl==pTbl){
                ret.push_back(i - pLen + 1);
            }
        }
        return ret;
    }
};