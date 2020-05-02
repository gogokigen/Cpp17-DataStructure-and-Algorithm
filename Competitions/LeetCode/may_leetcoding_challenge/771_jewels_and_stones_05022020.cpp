/*******************************************************************
* https://leetcode.com/problems/jewels-and-stones/
* Easy
* 
* Conception: 
*  1. 
*
* You're given strings J representing the types of stones that are jewels,
* and S representing the stones you have.
* Each character in S is a type of stone you have.
* You want to know how many of the stones you have are also jewels.
*
* The letters in J are guaranteed distinct, and all characters in J and S are letters.
* Letters are case sensitive, so "a" is considered a different type of stone from "A".
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
    int numJewelsInStones(string J, string S) {
        if(J.length() == 0 || S.length() == 0) return 0;
        int ret = 0;
        for(int i = 0; i < S.length(); i++){
            for(int j = 0; j < J.length();j++){
                if(S[i] == J[j]){
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};