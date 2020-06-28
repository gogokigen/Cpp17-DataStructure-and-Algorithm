/*******************************************************************
* https://leetcode.com/problems/shortest-distance-to-a-character/
* Easy
* 
* Conception: 
*  1.
*
* Given a string S and a character C,
* return an array of integers representing the shortest distance from the character C in the string.
*
*
* Example:
* Input: S = "loveleetcode", C = 'e'
* Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
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
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        vector<int> indexC;
        for(int i = 0; i < len; i++){
            if(S[i] == C){
                indexC.push_back(i);
            }
        }
        
        vector<int> ret;
        int indexCLen = indexC.size();
        int j = 0;
        for(int i = 0; i < len; i++){
            int dist = abs(i - indexC[j]);
            if( j + 1 < indexCLen && dist > abs(i - indexC[j + 1])){
                dist = abs(i - indexC[j + 1]);
                j++;
            }
            ret.push_back(dist);
        }
        return ret;
    }
};