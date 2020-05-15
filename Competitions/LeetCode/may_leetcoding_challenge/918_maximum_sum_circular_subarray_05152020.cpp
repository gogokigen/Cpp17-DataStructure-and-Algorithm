/*******************************************************************
* https://leetcode.com/problems/maximum-sum-circular-subarray/
* Medium
* 
* Conception: 
*  1. 
*
* Given a circular array C of integers represented by A,
* find the maximum possible sum of a non-empty subarray of C.
*
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0) return 0;
        if(A.size() == 1) return A[0];
        int m = *max_element(A.begin(), A.end());
        if (m <= 0) return m;
        
        int sum = 0;
        for(int i:A){
            sum += i;
        }

        //like max subarray
        int currSum = 0, maxSum = 0;
        for(int k = 0; k < A.size(); ++k) {
            currSum = max( 0, A[k]+currSum);
            maxSum = max(maxSum, currSum);
        }

        // circular case: total - min subarray
        int checkMin = 0;
        for(int k = 0; k < A.size(); ++k) {
            currSum = min( 0, A[k]+currSum);
            checkMin = min( checkMin, currSum);
        }


        return max(maxSum, sum - checkMin);
    }
};