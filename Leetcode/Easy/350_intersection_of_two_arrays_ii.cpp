/*******************************************************************
* https://leetcode.com/problems/intersection-of-two-arrays-ii/
* Easy
* 
* Conception: 
*  1. 
*
* Given two arrays, write a function to compute their intersection.
*
*
* Example:
* Input: nums1 = [1,2,2,1], nums2 = [2,2]
* Output: [2,2]
*
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ret;
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                ret.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] > nums2[j]){
                j++;
            } else {
                i++;
            }
        }
        return ret;
    }
};