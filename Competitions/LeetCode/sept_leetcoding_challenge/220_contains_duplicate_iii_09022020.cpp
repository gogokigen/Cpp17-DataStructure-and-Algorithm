/*******************************************************************
* https://leetcode.com/problems/contains-duplicate-iii/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of integers,
* find out whether there are two distinct indices i and j in the array
* such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference
* between i and j is at most k.
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<vector<int>> v;
        
        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size(); i++){  
            for(int j = i + 1; j < v.size(); j++){    
                if( v[j][0] > v[i][0] + t ) break;
                if( abs( v[j][1] - v[i][1] ) <= k) return 1;
            }
        }
        return 0;
    }
};