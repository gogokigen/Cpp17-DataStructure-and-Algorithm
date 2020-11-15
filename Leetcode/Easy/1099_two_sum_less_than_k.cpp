/*******************************************************************
* https://leetcode.com/problems/two-sum-less-than-k/
* Easy
* 
* Conception: 
*  1. 
*
* Given an array A of integers and integer K,
* return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K.
* If no i, j exist satisfying this equation, return -1.
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
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int left = 0, right = A.size()-1;
        int maxSum = -1;
        while (left < right) {
            if (K > A[left]+A[right]) {
                maxSum = max(maxSum, A[left]+A[right]);
                left++;
            } else 
                right--;
        }
        return maxSum;
    }
};