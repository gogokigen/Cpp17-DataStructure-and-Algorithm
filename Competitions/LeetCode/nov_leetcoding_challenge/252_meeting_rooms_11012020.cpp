/*******************************************************************
* https://leetcode.com/problems/meeting-rooms/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of meeting time intervals where intervals[i] = [starti, endi],
* determine if a person could attend all meetings.
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
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto const& a, auto const& b) {
            //sort each meeting by its end time
            return a[1] < b[1];
        });
        for (int i = 1; i < intervals.size(); i++) {
            //if a meeting ends after the next meeting starts you cannot attend both
            if (intervals[i][0] < intervals[i - 1][1]){
                return false;
            }
        }
        return true;
    }
};