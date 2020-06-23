/*******************************************************************
* https://leetcode.com/problems/set-matrix-zeroes/
* Medium
* 
* Conception: 
*  1. 
*
* Given a m x n matrix, if an element is 0, set its entire row and column to 0.
* Do it in-place.
*
*
* Example:
*
*
* Key:
*  1. more space to save row and col 
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int R = matrix.size();
        int C = matrix[0].size();
        vector<int> zeroRow(R, 0);
        vector<int> zeroCol(C, 0);
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(matrix[i][j] ==0){
                    zeroRow[i] = 1;
                    zeroCol[j] = 1;
                }
            }
        }

        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(zeroRow[i] == 1 || zeroCol[j] == 1){
                    matrix[i][j] = 0;

                }
            }
        }
        
    }
};