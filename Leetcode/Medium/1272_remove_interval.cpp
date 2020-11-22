/*******************************************************************
* https://leetcode.com/problems/remove-interval/
* Medium
* 
* Conception: 
*  1. 
*
* Given a sorted list of disjoint intervals,
* each interval intervals[i] = [a, b] represents the set of real numbers x such that a <= x < b.
* We remove the intersections between any interval in intervals and the interval toBeRemoved.
* Return a sorted list of intervals after all such removals.
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;

        for (auto& i : intervals){
            if (i[0] < toBeRemoved[0])
                result.push_back({ i[0], min(i[1], toBeRemoved[0]) });

            if (i[1] > toBeRemoved[1])
                result.push_back({ max(i[0], toBeRemoved[1]), i[1] });
        }

        return result;
    }
};