/*******************************************************************
* https://leetcode.com/problems/longest-consecutive-sequence/
* Hard
* 
* Conception: 
*  1. 
*
* Given an unsorted array of integers nums,
* return the length of the longest consecutive elements sequence.
*
* Follow up: Could you implement the O(n) solution? 
*
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
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        unordered_set<int> record(nums.begin(), nums.end());
        int res = 1;
        for(int n : nums){
            if(record.find(n) == record.end()){
                continue;
            }else{
                record.erase(n);
                int prev = n-1, next = n+1;

                while(record.find(prev) != record.end()){
                    record.erase(prev--);
                }
                
                while(record.find(next)!=record.end()){
                    record.erase(next++);
                }
                
                res = max(res, next - prev - 1);
            }
        }
        return res;
    }
};