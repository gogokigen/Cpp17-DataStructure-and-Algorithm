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
        // Find the intersection point of the two runners.
        int fast = nums[0];
        int slow = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            //cout << "fast: " << fast << ", slow: " << slow << endl;
        } while (fast != slow);
        cout << "~"<< endl;
        //if fast == slow
        slow = nums[0];
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
            //cout << "fast: " << fast << ", slow: " << slow << endl;
        }
        return fast;
        
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