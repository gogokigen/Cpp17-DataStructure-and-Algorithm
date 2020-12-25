/*******************************************************************
* https://leetcode.com/problems/two-sum/
* Easy
* Conception: map can save the value of "target - nums[i]"
*
* Given an array of integers,
* return indices of the two numbers such that they add up to a specific target.
* 
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
*
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
*******************************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> temp(nums);
        if(nums.size() < 2) return {};
        int l = 0, r = nums.size()-1;

        sort(nums.begin(), nums.end());

        vector<int> result;
        while( l < r){
            if(nums[l]+nums[r]==target){  
                break;
            } else if(nums[l]+nums[r]>target){
                r--;
            } else if(nums[l]+nums[r]<target) {
                l++;
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]==nums[l] || temp[i]==nums[r]){
                result.push_back(i);
            }
        }
        return result;
    }
};



#include <iostream>
#include <vector> //for vector
#include <map> //for map
using namespace std;


class Solution {
public:
    Solution(){};
    //Brute Force, Time complexity: O(n^2); Space complexity: O(1); 
    vector<int> twoSum_brute(vector<int>& nums, int target) {
        vector<int> ret;
        for ( int i = 0; i < size(nums) - 1; i++){
            for ( int j = i + 1; j < size(nums); j++){
                if ( target - nums[i] == nums[j]){
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }

    //One-pass Hash Table, Time complexity: O(n); Space complexity: O(n); 
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> cache;
        for ( int i = 0; i < size(nums); i++){
            int tmp = target - nums[i];
            
            map<int,int>::iterator it = cache.find(tmp);
            if (it == cache.end()) {
                cout << "Not Fount" << endl;
            } else {
                ret.push_back(it->second);
                ret.push_back(i);
                return ret;
            }
            cache.insert(pair<int, int>(nums[i],i));
        }
        return ret;
    }
};

int main()
{
    //Test Cases
    vector<int> nums = { 3, 2, 4}; //ret: 1 , 2
    int target = 6;
    //vector<int> nums = { 2, 7, 11, 15}; //ret: 0 , 1
    //int target = 9;
    
    Solution* sol = new Solution;
    vector<int> ret;
    ret = sol->twoSum_hash(nums , target);

    for(auto n : ret) {
        cout << n << endl;
    }
    return 0;
}
