/*******************************************************************
* https://leetcode.com/problems/image-overlap/
* Medium
* 
* Conception: 
*  1. 
*
* Two images A and B are given, represented as binary,
* square matrices of the same size. 
* (A binary matrix has only 0s and 1s as values.)
*
* We translate one image however we choose (sliding it left, right, up, or down any number of units),
* and place it on top of the other image.
* After, the overlap of this translation is the number of positions that have a 1 in both images.
*
* (Note also that a translation does not include any kind of rotation.)
*
* What is the largest possible overlap?
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
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                res = max({res, getOverlap(A, B, i, j), getOverlap(B, A, i, j)});
            }
        }

        return res;
    }

    int getOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int offi, int offj){
        int res = 0;
        for(int i = offi; i < A.size(); i++){
            for(int j = offj; j < A[0].size(); j++){
                res += A[i][j]*B[i-offi][j-offj];
            }
        }

        return res;
    }
};