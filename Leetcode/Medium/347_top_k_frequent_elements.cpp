/*******************************************************************
* https://leetcode.com/problems/top-k-frequent-elements/
* Medium
* 
* Conception: 
*  1. 
*
* Given a non-empty array of integers, return the k most frequent elements.
*
* Key:
*  - heap
*
*
* Explanation:
*
* References:
*  1.
*
*******************************************************************/
class Solution {
private:
    struct comp{
        bool operator()(const pair<int,int>& p1,
                        const pair<int,int>& p2){
            return p1.second > p2.second;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //calculate num:freq
        unordered_map<int, int> map_num_freq;
        for(int& n:nums){
            map_num_freq[n]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> maxHeap;
        
        for(auto& m:map_num_freq){
            maxHeap.push(m);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return ans;
    }
};
