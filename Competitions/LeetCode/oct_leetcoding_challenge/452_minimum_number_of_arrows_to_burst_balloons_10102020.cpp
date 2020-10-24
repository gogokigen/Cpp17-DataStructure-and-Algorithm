/*******************************************************************
* https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
* Medium
* 
* Conception: 
*  1. 
*
* Serialization is converting a data structure or object into a sequence of bits
* so that it can be stored in a file or memory buffer,
* or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
*
* Design an algorithm to serialize and deserialize a binary search tree.
* There is no restriction on how your serialization/deserialization algorithm should work.
* You need to ensure that a binary search tree can be serialized to a string,
* and this string can be deserialized to the original tree structure.
*
* The encoded string should be as compact as possible.
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
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sorting by start coordinates of the balloon.
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int minimum_arrow_shots = 0, i = 0;
        while (i < points.size()) {
            int end = points[i++][1];
            
            // Increasing the arrow count. (This is either the first balloon or the previous arrow was unable to burst the balloon.)
            minimum_arrow_shots++;
            
            while(i < points.size() && points[i][0] <= end) {
                // Current arrow can be used to burst this balloon as well.
                end = min(end, points[i++][1]);
            }
        }
        return minimum_arrow_shots;
    }
};