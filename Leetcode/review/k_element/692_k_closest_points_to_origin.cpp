/*******************************************************************
* https://leetcode.com/problems/k-closest-points-to-origin/
* Medium
* 
* Conception: 
*  1. 
*
* Given a non-empty list of words, return the k most frequent elements.
* Your answer should be sorted by frequency from highest to lowest.
* If two words have the same frequency,
* then the word with the lower alphabetical order comes first.
*
* Key:
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
    struct comp{
        bool operator()(const pair<string,int>& p1,
                        const pair<string,int>& p2){
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //calculate num:freq
        unordered_map<string, int> map_word_freq;
        for(string& w:words){
            map_word_freq[w]++;
        }
        
        priority_queue<pair<string,int>, vector<pair<string,int>>, comp> maxHeap;
        
        for(auto& m:map_word_freq){
            maxHeap.push(m);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<string> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        //sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};