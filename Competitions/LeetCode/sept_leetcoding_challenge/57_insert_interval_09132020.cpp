/*******************************************************************
* https://leetcode.com/problems/insert-interval/
* Hard
* 
* Conception: 
*  1. 
*
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* You may assume that the intervals were initially sorted according to their start times.
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        deque<vector<int>> dq;
        dq.push_back(newInterval);
        
        for (auto& i : intervals) {
            auto last = dq.back();
            dq.pop_back();
            
            if (i[1] < last[0]) {
                dq.push_back(i);
                dq.push_back(last);
            } else if (i[0] > last[1]) {
                dq.push_back(last);
                dq.push_back(i);
            } else {
                last[0] = min(last[0], i[0]);
                last[1] = max(last[1], i[1]);
                
                dq.push_back(last);
            }
        }
        
        return vector(dq.begin(), dq.end());
    }
};