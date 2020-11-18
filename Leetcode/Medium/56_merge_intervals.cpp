/*******************************************************************
* https://leetcode.com/problems/merge-intervals/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of intervals where intervals[i] = [starti, endi]
* merge all overlapping intervals,
* and return an array of the non-overlapping intervals that cover all the intervals in the input.
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) -> bool{ 
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] < b[0];
             });
        vector<int> prev = intervals[0];
        vector<vector<int>> ret;
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> inter = intervals[i];
            if (inter[0] > prev[1]) {
                ret.push_back(prev);
                prev = inter;
            }else if(inter[1] > prev[1]) {
                prev[1] = max( prev[1], inter[1]);
            }
        }
        ret.push_back(prev);
        return ret;
    }
};