/*******************************************************************
* https://leetcode.com/problems/median-of-two-sorted-arrays/
* Hard
* 
* Conception: 
*  1. 
*
* Given two sorted arrays nums1 and nums2 of size m and n respectively,
* return the median of the two sorted arrays.
*
* Follow up: The overall run time complexity should be O(log (m+n)).
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
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0) return len2 % 2 == 0 ? (nums2[len2/2 - 1] + nums2[len2/2] )/2.0 : nums2[len2/2];
        if (len2 == 0) return len1 % 2 == 0 ? (nums1[len1/2 - 1] + nums1[len1/2] )/2.0 : nums1[len1/2];
        
        if (len1 > len2){ // check len1 <= len2
            return findMedianSortedArrays(nums2, nums1);
        }
        int len = len1 + len2;
        int left = 0, right = len1;
        while(left <= right){
            int cut1 = left + (right - left) / 2;
            int cut2 = len/2 - cut1;
            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int R1 = (cut1 == len1) ? INT_MAX : nums1[cut1];
            int R2 = (cut2 == len2) ? INT_MAX : nums2[cut2];
            
            if(R1 < L2){ // [array 1] | [array2]
                left = cut1 + 1;
            } else if (L1 > R2) {// [array 2] | [array1]
                right = cut1;
            } else {
                if( len % 2 == 0){
                    return (max(L1, L2) + min(R1, R2)) / 2.0;
                } else {
                    return min(R1, R2);
                }
            }
            
        }
        return -1;
    }
};