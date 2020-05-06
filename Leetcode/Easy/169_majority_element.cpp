/*******************************************************************
* https://leetcode.com/problems/majority-element/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array of size n, find the majority element.
* The majority element is the element that appears more than [n/2] times.
*
* You may assume that the array is non-empty and the majority element always exist in the array.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
//Method 1: Moore vote algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
        int count = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[major] == nums[i]){
                count++;
            }else{
                count--;
            }
            
            if(count == 0){
                major = i;
                count = 1;
            }
        }
        return nums[major];
    }
};

//Method 2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int>tbl;
        for(int i = 0; i < nums.size();i++){
            tbl[nums[i]]++;
        }
        
        for(auto i:tbl){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }
        return -1;
    }
};