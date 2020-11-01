/*******************************************************************
* https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
* Medium
* 
* Conception: 
*  1. 
*
* Given an integer array sorted in ascending order,
* write a function to search target in nums.
* If target exists, then return its index, otherwise return -1.
* However, the array size is unknown to you.
* You may only access the array using an ArrayReader interface,
* where ArrayReader.get(k) returns the element of the array at index k (0-indexed).
*
* You may assume all integers in the array are less than 10000,
* and if you access the array out of bounds, ArrayReader.get will return 2147483647.
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
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:

    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 10000;

        while(left <= right){
            int mid = (left + right) / 2;
            if(reader.get(mid) <= target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(left-1 < 0) return -1;
        if(reader.get(left-1) == target) return left-1;

        return -1;
    }
};