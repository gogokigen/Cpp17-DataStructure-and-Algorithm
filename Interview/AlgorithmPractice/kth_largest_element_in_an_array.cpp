/*******************************************************************
* https://leetcode.com/problems/kth-largest-element-in-an-array/
* Medium
* 
* Conception: 
*  1. priority_queue
*
* Find the kth largest element in an unsorted array.
* Note that it is the kth largest element in the sorted order, not the kth distinct element.
*
* Example:
* [3,2,1,5,6,4]
* 
* Explanation:
* 3 -> 3
* 2 -> 2, 3
* 1 -> x
* 5 -> 3
*      3,5
* 6 -> 5
*      5,6
* 4 -> x
* 
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> queue;
        
        for(int& n:nums){
            cout <<  n << endl;
            if( queue.size() != k || n > queue.top()){
                if(queue.size() == k){
                    queue.pop();
                }
                queue.push(n);
            }
        }
        return queue.top();        
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //int len = nums.size();
        if(nums.size()<k) return -1;
        nth_element(nums.begin(),nums.end()-k,nums.end());
        return nums[nums.size()-k];        
    }
};