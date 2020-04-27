/*******************************************************************
* https://leetcode.com/problems/rotate-array/
* Easy
* 
* Conception: 
*  1. circle
*
* Given an array, rotate the array to the right by k steps, where k is non-negative.
*
*
* Example: [ 1, 2, 3], k=2
*  i  count   next   curr   num[next]   tmp->prev
*  0    0      2       2    [ 1, 2, 1]     3
*       1      1       1    [ 1, 3, 1]     2
*       2      0       0    [ 2, 3, 1]
*
*  1 ...
*
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
            do{
                int next = (curr + k )%n;
                
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                curr = next;
                count++;
            }while(i != curr);
        }
    }
};