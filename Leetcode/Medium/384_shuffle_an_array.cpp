/*******************************************************************
* https://leetcode.com/problems/shuffle-an-array/
* Medium
* 
* Conception: 
*  1. 
*
* Shuffle a set of numbers without duplicates. 
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
class Solution {
public:
    Solution(vector<int>& nums) {
        n = nums;
    }
    
    vector<int> reset() {
        return n;
    }
    
    vector<int> shuffle() {
        vector<int> res(n.begin(), n.end());
        int size = res.size();
        for(int i = 0; i < size; ++i){
            swap(res[i], res[i + rand() % (size-i)]);
            size = res.size();
        }
        return res;
    }
    
    vector<int> n;
};
