/*******************************************************************
* https://leetcode.com/problems/sliding-window-maximum/
* Hard
* 
* Conception: 
*  1. 
*
* You are given an array of integers nums,
* there is a sliding window of size k
* which is moving from the very left of the array to the very right.
* You can only see the k numbers in the window.
* Each time the sliding window moves right by one position.
*
* Return the max sliding window.
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++) pq.push({nums[i], i});
        vector<int> ans;
        for(int i = k, j = 0; i <= nums.size(); i++, j++){
            while(pq.top().second < j){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            if(i<nums.size()){
                pq.push({nums[i], i});
            }
        }
        return ans;
    }
};
