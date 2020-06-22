/*******************************************************************
* https://leetcode.com/problems/single-number-ii/
* Medium
* 
* Conception: 
*  1. Binary search
*
* Given a non-empty array of integers, every element appears three times except for one,
* which appears exactly once. Find that single one.
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
//Magic
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for (int num : nums) {
          // first appearence: 
          // add num to seen_once 
          // don't add to seen_twice because of presence in seen_once

          // second appearance: 
          // remove num from seen_once 
          // add num to seen_twice

          // third appearance: 
          // don't add to seen_once because of presence in seen_twice
          // remove num from seen_twice
          seenOnce = ~seenTwice & (seenOnce ^ num);
          seenTwice = ~seenOnce & (seenTwice ^ num);
        }

        return seenOnce;
    }
};

// Easy
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> tbl;
        int len = nums.size();
        for(int i = 0; i < len; i++){
            tbl[nums[i]] += 1;
        }
        for(auto t:tbl){
            if(t.second == 1){
                return t.first;
            }
        }

        return -1;
    }
};