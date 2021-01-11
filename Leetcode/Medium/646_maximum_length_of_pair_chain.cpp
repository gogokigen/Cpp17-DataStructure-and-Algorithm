/*******************************************************************
* https://leetcode.com/problems/maximum-length-of-pair-chain/
* Medium
* 
* Conception: 
*  1. 
*
* You are given n pairs of numbers. In every pair,
* the first number is always smaller than the second number.
*
* Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c.
* Chain of pairs can be formed in this fashion.
*
* Given a set of pairs, find the length longest chain which can be formed.
* You needn't use up all the given pairs. You can select pairs in any order. 
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
    static bool comp(vector<int> a, vector<int> b){
        return (a[0] < b[0]);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0) return 0;

        sort(pairs.begin(), pairs.end(), comp);
        vector<int> dp(pairs.size(), 1);

        int ans = 1;
        int len = pairs.size();
        for(int i = 1; i < len; i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
