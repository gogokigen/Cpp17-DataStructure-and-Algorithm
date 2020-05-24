/*******************************************************************
* https://leetcode.com/problems/interval-list-intersections/
* Medium
* 
* Conception: 
*  1. 
*
* Given two lists of closed intervals,
* each list of intervals is pairwise disjoint and in sorted order.
*
* Return the intersection of these two interval lists.
*
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ret;
        int i = 0, j = 0;
        while( i < A.size()&& j < B.size()){
            int left = max(A[i][0], B[j][0]);
            int right = min(A[i][1], B[j][1]);
            if(left <= right){
             ret.push_back({left,right});
            }
            if(A[i][1]<B[j][1]){
                i++;
            } else {
                j++;
            }
        }
        return ret;
    }
};