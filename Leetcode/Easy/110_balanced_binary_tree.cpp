/*******************************************************************
* https://leetcode.com/problems/balanced-binary-tree/
* Easy
* 
* Conception: 
*  1. 
*
* Given a binary tree, determine if it is height-balanced.
*
* For this problem, a height-balanced binary tree is defined as:
*    a binary tree in which the left and right subtrees of every node
*    differ in height by no more than 1.
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
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1) return false;
        set<int> cache;

        for(int i = 0; i < nums.size(); i++){
            if(cache.find(nums[i]) != cache.end()){//exist
                return true;
            }else{
                cache.insert(nums[i]);
            }
        }
        return false;
    }
};