/*******************************************************************
* https://leetcode.com/problems/buddy-strings/
* Easy
* 
* Conception: 
*  1. 
*
* Given two strings A and B of lowercase letters,
* return true if you can swap two letters in A so the result is equal to B,
* otherwise, return false.
*
* Swapping letters is defined as taking two indices i and j (0-indexed)
* such that i != j and swapping the characters at A[i] and A[j].
* For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
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
    bool buddyStrings(string A, string B) {
        int a[26]={0},f=0;
        vector<char>v,v1;
        if(A.length() != B.length()) return false;

        for(int i = 0; i < A.length(); i++){
            if(A[i]!=B[i]){
                v.push_back(A[i]);
                v1.push_back(B[i]);
            } else {
                a[A[i]-'a']++;
                if(a[A[i]-'a']%2 == 0){
                    f = 1;
                }
            }
        }
        if(v.size() > 2) return false;

        if(v.size() < 2 && f == 0) return false;
        if(v.size() == 1) return false;
        if(v.size() == 0 && f == 1) return true;
        if(v[0] == v1[1] && v[1] == v1[0]) return true;

        return false;
    }
};