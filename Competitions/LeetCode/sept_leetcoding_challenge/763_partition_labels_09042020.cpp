/*******************************************************************
* https://leetcode.com/problems/partition-labels/
* Medium
* 
* Conception: 
*  1. 
*
* A string S of lowercase English letters is given.
* We want to partition this string into as many parts as possible
* so that each letter appears in at most one part,
* and return a list of integers representing the size of these parts.
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. 
*
*******************************************************************/vector<int> partitionLabels(string S) {
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> partitions;
        int last['z'-'a'+1];

        for (int i = 0; i < S.size(); ++i)
            last[S[i] - 'a'] = i;

        for (int i = 0, size = 1, end = 0; i < S.size(); ++i, ++size) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partitions.push_back(size);
                size = 0;
            }
        }

        return partitions;
    }
};