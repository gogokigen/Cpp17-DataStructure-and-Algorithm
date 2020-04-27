/*******************************************************************
* https://leetcode.com/problems/rotate-image/
* Medium
* 
* Conception: 
*  1. 
*
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
*
*
* Explanation:
*   *   -  (c,r)  -    *        -      *
*   |        |         |               |
*   *   -    *    -    *        -      *
*   |        |         |               |
*(n-1-c,r) - *    -    *        -  (c,n-1-r)
*   |        |         |               |
*   *   -    *   - (n-1-r,n-c-1) -     *
*******************************************************************/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r < (n+1)/2; r++){
            for(int c = 0; c < n/2; c++){
                int tmp = matrix[n - 1 -c][r];
                matrix[n - 1 - c][r] = matrix[n - 1 - r][n - 1 - c];
                matrix[n - 1 - r][n - 1 - c] = matrix[c][n - 1 - r];
                matrix[c][n - 1 - r] = matrix[r][c];
                matrix[r][c] = tmp;
            }
        }
    }
};