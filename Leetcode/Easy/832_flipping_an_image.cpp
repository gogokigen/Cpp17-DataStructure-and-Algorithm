/*******************************************************************
* https://leetcode.com/problems/flipping-an-image/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary matrix A, we want to flip the image horizontally,
* then invert it, and return the resulting image.
*
* To flip an image horizontally means that each row of the image is reversed.
* For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
*
* To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
* For example, inverting [0, 1, 1] results in [1, 0, 0].
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (int i=0; i<A.size(); i++) {
            reverse(A[i].begin(), A[i].end());
            for (int j=0; j<A[i].size(); j++) {
                A[i][j] ^= 0x1;
            }
        }
        return A;
    }
};