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
//window slicing
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;

        deque<int> dq; //save the positions which numbers are kth large. 
        
        for (int start = 0; start < nums.size(); start++) {
            while (!dq.empty() && (start - dq.front() >= k)){
                // keep size of dq <= k
                dq.pop_front();
            }
            
            while (!dq.empty() && (nums[start] > nums[dq.back()])){
                // save the pre kth large
                dq.pop_back();
            }
            
            dq.push_back(start);
            
            if (start >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // deafult is decreasing by first

        for(int i = 0; i < k; i++){
            //the num of starting window, the pos of starting window
            pq.push({nums[i], i});
        }
        
        vector<int> ans;
        for(int i = k, j = 0; i <= nums.size(); i++, j++){
            while(pq.top().second < j){
                pq.pop();
            }
            
            ans.push_back(pq.top().first);
            
            if(i < nums.size()){
                pq.push({nums[i], i});
            }
        }
        return ans;
    }
};
