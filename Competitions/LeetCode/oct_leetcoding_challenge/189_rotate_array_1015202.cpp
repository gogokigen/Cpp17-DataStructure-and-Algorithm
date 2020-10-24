/*******************************************************************
* https://leetcode.com/problems/rotate-array/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array, rotate the array to the right by k steps, where k is non-negative.
*
* Follow up:
*    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*    Could you do it in-place with O(1) extra space?
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
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0;
        for(int i = 0; count < n; i++){
            int curr = i;
            int prev = nums[i];
            //cout << "i: " << i << endl;
            do{
                int next = (curr + k )%n;
                //cout << "curr: " << curr << " next: " << next << endl;
                
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                
                curr = next;
                count++;
            }while(i != curr);
        }
    }
};