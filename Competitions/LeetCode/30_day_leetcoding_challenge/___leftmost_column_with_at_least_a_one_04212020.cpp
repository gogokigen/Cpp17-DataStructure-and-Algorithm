/*******************************************************************
* https://...
* Medium
* 
* Conception: 
*  1. 
*
* A binary matrix means that all elements are 0 or 1.
* For each individual row of the matrix, this row is sorted in non-decreasing order.
*
* Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it.
* If such index doesn't exist, return -1.
*
* You can't access the Binary Matrix directly.
* You may only access the matrix using a BinaryMatrix interface:
*
*    BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
*    BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m
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
​/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int row = dim[0];
        int col = dim[1];
        int ret = col;
        int i = 0;
        int j = col - 1;
        while(i < row &&  j >= 0){
            if(binaryMatrix.get(i,j)!=0){
                ret = j;
                j--;
            }else{
                i++;
            }
        }

        if(ret == col) return -1;
        return ret;
    }
};