/*******************************************************************
* https://leetcode.com/problems/find-the-duplicate-number/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
* prove that at least one duplicate number must exist.
* Assume that there is only one duplicate number, find the duplicate one.
*
* Example:
*
*
* Key:
*  1. 
*
* References:
*  1. 
*
*******************************************************************/
//find cycle
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        int len = nums.size();
        
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow) break;
        }
        
        fast = 0;
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


//set
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> cache;
        
        for(int& i:nums){
            if(cache.find(i) == cache.end()){
                cache.insert(i);
            }else{
                return i;
            }
        }
        return -1;
    }
};
