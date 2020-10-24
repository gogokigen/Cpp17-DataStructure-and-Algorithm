/*******************************************************************
* https://leetcode.com/problems/meeting-rooms-ii/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
* find the minimum number of conference rooms required.
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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int intervals_size = intervals.size();
        vector<int> starts(intervals_size, 0);
        vector<int> ends(intervals_size, 0);

        for(int i = 0; i < intervals_size; i++){
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int i = 0, j = 0;//i: starts j:ends
        int res_max = 0;
        int curr;

        while(i < starts.size()){
            curr = 0;
            int left = starts[i];
            int right = ends[i];
            while(i < starts.size()){
                if(starts[i] >= right){//end
                    j = i;
                    break;
                }
                if( i < starts.size() && starts[i] < ends[j]){
                    curr++;
                    res_max = max(curr, res_max);
                    right = ends[i];
                    i++;
                } else{
                    curr--;
                    j++;
                }
            }
        }
        return res_max;
    }
};