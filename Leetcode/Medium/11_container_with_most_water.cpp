/*******************************************************************
* https://leetcode.com/problems/container-with-most-water/
* Medium
* 
* Conception: 
*  1. 
*
* Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
* Find two lines, which together with x-axis forms a container,
* such that the container contains the most water.
*
* Note: You may not slant the container and n is at least 2.
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
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ret = 0;
        int t_height = 0, t_size = 0;
        while(left <= right){
            t_height = min(height[left] , height[right]);
            ret = max(ret, t_height * (right - left));
            if(height[left] >= height[right]){
                right--;
            }else{
                left++;
            }
        }
        return ret;
    }
};