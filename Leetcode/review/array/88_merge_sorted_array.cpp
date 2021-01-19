/*******************************************************************
* https://leetcode.com/problems/merge-sorted-array/
* Easy
* 
* Conception: 
*  1. 
*
* Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*
* Note:
*
*    The number of elements initialized in nums1 and nums2 are m and n respectively.
*    You may assume that nums1 has enough space (size that is greater or equal to m + n)
*    to hold additional elements from nums2.
*
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int mLen = m-1, nLen = n-1, totalLen = m+n-1;
        while(mLen >= 0 && nLen >= 0) {
            if(nums1[mLen] > nums2[nLen]) {
                nums1[totalLen] = nums1[mLen];
                totalLen--;
                mLen--;
            } else {
                nums1[totalLen] = nums2[nLen];
                totalLen--;
                nLen--;
            }
        }

        while(nLen >= 0){
            nums1[totalLen] = nums2[nLen];
            totalLen--;
            nLen--;
        }
    }
};