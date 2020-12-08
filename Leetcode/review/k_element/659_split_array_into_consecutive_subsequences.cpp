/*******************************************************************
* https://leetcode.com/problems/split-array-into-consecutive-subsequences/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array nums sorted in ascending order, return true if and only if
* you can split it into 1 or more subsequences such that
* each subsequence consists of consecutive integers and has length at least 3.
*
* Key:
*
* Explanation:
*
* References:
*  1. https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C%2B%2B-O(n)-solution-two-pass
*  2. https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/944317/C%2B%2B-Easy-Heap-Hashmap
*
*******************************************************************/
class Solution {
//tails to record extra information,
// where tails[i] means the number of consecutive subsequences we've found so far,
// who are longer than 3 , and tailed by number i,
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> first, tail;
        
        for(int& i:nums) first[i]++;
        
        for(int& i:nums){
            if(!first[i]) continue;
            
            first[i]--;
            if(tail[i-1] > 0){
                tail[i-1]--;
                tail[i]++;
            } else if (first[i + 1] > 0 && first[i + 2] > 0 ){
                first[i + 1]--;
                first[i + 2]--;
                tail[i+2]++;
            }else{
                return false;
            }
        }
        return true;
    }
};


//Heap: slow
class Solution {
public:    
    bool isPossible(vector<int>& nums) {  
        int N = nums.size();  
        //Stores subsequences. Subsequence with smaller final element toward top. 
        priority_queue<vector<int>, vector<vector<int>>, comp> pq_order; 
        //For each integer in nums, stores # of occurences in nums.
        map<int, int> map_num_freq; 
        
        for (int i = 0; i < N; i++) {
            map_num_freq[nums[i]]++;
        }
        
        for (auto& n : map_num_freq) {
            int x = n.first;
            while (map_num_freq[x] > 0) {
                //If last element < x-1, can't append x, so pop.
                while (!pq_order.empty() && pq_order.top().back() < x-1) {
                    pq_order.pop();
                }
                //If last element == x-1, then append x.
                if (!pq_order.empty() && pq_order.top().back() == x-1) {
                    vector<int> temp = pq_order.top();
                    temp.push_back(x);
                    map_num_freq[x]--;
                    pq_order.pop();
                    pq_order.push(temp);
                }
                //Now, last element >= x, so can't append.
                //Form new sequence of 3 elements and add to heap.
                else if (map_num_freq[x+1] > 0 && map_num_freq[x+2] > 0) {
                    vector<int> temp = {x, x+1, x+2};
                    pq_order.push(temp);
                    map_num_freq[x]--;
                    map_num_freq[x+1]--;
                    map_num_freq[x+2]--;
                }
                //Can't append x nor create new sequence.
                else {
                    return false;
                }
            }
        }
        
        return true;
    }

private:
    struct comp {
        //Return false puts first element closer to top.
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return (a.back() > b.back());
        }
    };
};