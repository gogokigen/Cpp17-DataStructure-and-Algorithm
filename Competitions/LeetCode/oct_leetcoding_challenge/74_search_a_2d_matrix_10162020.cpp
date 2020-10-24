/*******************************************************************
* https://leetcode.com/problems/search-a-2d-matrix/
* Medium
* 
* Conception: 
*  1. 
*
* Write an efficient algorithm that searches for a value in an m x n matrix.
* This matrix has the following properties:
*    Integers in each row are sorted from left to right.
*    The first integer of each row is greater than the last integer of the previous row.
*
*
* Example:
*
* Key:
*  1. binary search
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int M = matrix.size();
        int N = matrix[0].size();
        int left = 0, right = M-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == matrix[mid][0])
                return true;
            if (target < matrix[mid][0]) {
                right = mid-1;
            } else if (target > matrix[mid][N-1]){
                left = mid+1;
            } else {
                left = mid;
                break;
            }
        }
        int row = left;
        left = 0, right = N-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == matrix[row][mid])
                return true;
            if (target < matrix[row][mid]) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return matrix[row][left] == target ? true : false;
    }
};