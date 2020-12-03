/*******************************************************************
* https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
* Medium
* 
* Conception: 
*  1. 
*
* Given a n x n matrix where each of the rows and columns are sorted in ascending order,
* find the kth smallest element in the matrix.
*
* Note that it is the kth smallest element in the sorted order, not the kth distinct element. 
*
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
    int search_less_equal( vector<vector<int>>& matrix, int target){
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while( i >= 0 && j < n){
            if( target < matrix[i][j]){
                i--;
            }else{
                j++;
                res += i + 1;
            }
        }
        return res;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = 0, right = matrix.back().back();
        while( left < right){
            int mid = left + (right - left) /2;
            int count = search_less_equal(matrix, mid);
            if( count < k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }
};