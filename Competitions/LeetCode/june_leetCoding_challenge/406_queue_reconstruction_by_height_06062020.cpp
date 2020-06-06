/*******************************************************************
* https://leetcode.com/problems/queue-reconstruction-by-height/
* Medium
* 
* Conception: 
*  1. 
*
* Suppose you have a random list of people standing in a queue.
* Each person is described by a pair of integers (h, k),
* where h is the height of the person and k is the number of people in front of this person
* who have a height greater than or equal to h.
*
* Write an algorithm to reconstruct the queue.
*
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
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),[](vector<int>&a, vector<int>& b){
                   return (a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]); 
               }
            );
        vector<vector<int>> ans;
        for(auto i:people){
            int height = i[1];
            ans.insert(ans.begin() + height, i);
        }
        return ans;
    }
};
