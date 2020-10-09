/*******************************************************************
* https://leetcode.com/problems/maximum-distance-in-arrays/
* Medium
* 
* Conception: 
*  1. 
*
* You are given m arrays, where each array is sorted in ascending order.
* Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance.
* We define the distance between two integers a and b to be their absolute difference |a - b|.
* Your task is to find the maximum distance.
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
    int maxDistance(vector<vector<int>>& arrays) {
        int min_value = arrays[0].front();
        int max_value = arrays[0].back();
        int max_distance = 0;
        for (int i = 1; i < size(arrays); ++i) {
            max_distance = max(
                max(abs(max_value - arrays[i].front()), max_distance),
                max(abs(min_value - arrays[i].back()), max_distance)
            );
            min_value = min(min_value, arrays[i].front());
            max_value = max(max_value, arrays[i].back());
        }
        return max_distance;
    }
};