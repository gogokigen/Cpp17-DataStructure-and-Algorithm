/*******************************************************************
* https://leetcode.com/problems/random-pick-with-weight/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array w of positive integers,
* where w[i] describes the weight of index i,
* write a function pickIndex which randomly picks an index in proportion to its weight.
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
class Solution {
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        for(int i:w){
            prefixSum.push_back(i + (prefixSum.empty()? 0 : prefixSum.back()));
        }
    }
    
    int pickIndex() {
        float randNum = (float) rand()/ RAND_MAX;
        float target = randNum * prefixSum.back();
        
        //binary search
        int left = 0, right = prefixSum.size() - 1;
        int mid = 0;
        while(left < right){
            mid = left + (right - left ) /2;
            if (target > prefixSum[mid]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};