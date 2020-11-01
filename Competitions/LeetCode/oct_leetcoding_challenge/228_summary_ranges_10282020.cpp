/*******************************************************************
* https://leetcode.com/problems/summary-ranges/
* Easy
* 
* Conception: 
*  1. 
*
* You are given a sorted unique integer array nums.
*
* Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
* That is, each element of nums is covered by exactly one of the ranges,
* and there is no integer x such that x is in one of the ranges but not in nums.
*
* Each range [a,b] in the list should be output as:
*    "a->b" if a != b
*    "a" if a == b
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
    vector<string> summaryRanges(vector<int>& ar) {
        if (ar.empty()) return {};
        vector<string> ans;
        int s = 0, e = 0, i = 1;
        while(i <= ar.size()) {
            if (i < ar.size() && ar[i] == ar[e] + 1) {
                e++;
            } else {
                ans.push_back(to_string(ar[s]));
                if (s != e) ans.back() += "->" + to_string(ar[e]);
                s = e = i;
            }
            i++;
        }
        return ans;
    }
};