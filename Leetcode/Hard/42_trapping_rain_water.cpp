/*******************************************************************
* https://leetcode.com/problems/trapping-rain-water/
* Hard
* 
* Conception: 
*  1. 
*
* Given n non-negative integers representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
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
    int trap(vector<int>& height) {
        int sum_water = 0;
        int h_size = height.size();
        vector<int> L_maxH(h_size,0);
        vector<int> R_maxH(h_size,0);
        if (h_size==0) return 0;
        L_maxH[0] = height[0];
        for(int i = 1; i < height.size() - 1; i++){
            L_maxH[i] = max(height[i],L_maxH[i-1]);
        }
        R_maxH[h_size-1] = height[h_size-1];
        for(int i = h_size-2; i >=0; i--){
            R_maxH[i] = max(height[i],R_maxH[i+1]);
        }
        
        for(int k = 1; k < height.size()-1; k++ ){
            sum_water += min(L_maxH[k],R_maxH[k]) - height[k];
        }
        return sum_water;
    }
};