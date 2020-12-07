/*******************************************************************
* https://leetcode.com/problems/find-k-th-smallest-pair-distance/
* Hard
* 
* Conception: 
*  1. 
*
* Given an integer array, return the k-th smallest distance among all the pairs.
* The distance of a pair (A, B) is defined as the absolute difference between A and B. 
*
*
* Example:
*
* Key:
*  1.
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mi){
                    left++;
                }
                count += right - left;
            }

            //count = number of pairs with distance <= mi
            if (count >= k){
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};


//Heap, but TLE
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());//O(nlgn)
        int len = nums.size();
        priority_queue<pip,vector<pip>,comp> minHeap;
        for(int i = 0; i < len-1; i++){
            int diff = abs(nums[i] - nums[i+1]);
            minHeap.push({diff, i, i+1});
        }
        while(--k && !minHeap.empty()){
            auto u = minHeap.top();
            minHeap.pop();
            int x = u[1];
            int y = u[2];
            if(y < len-1){
                int newDiff = abs(nums[x] - nums[y+1]);
                minHeap.push({newDiff, x, y+1});
            }
        }
        return minHeap.top()[0];
    }
private:
    //1st-diff, 2nd-index of start ele, 3rd-index of prob ele
    using pip = vector<int>;
    struct comp{
        bool operator()(const pip& a, const pip& b){
            return a[0] > b[0];
        }
    };
};