/*******************************************************************
* https://leetcode.com/problems/number-of-longest-increasing-subsequence/
* Medium
* 
* Conception: 
*  1. 
*
* Given an integer array nums, return the number of longest increasing subsequences.
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
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        if(n == 0) return 0;

        int lis[n],con[n];int count=0;int currmax=0;

        for(int i=0;i<n;i++){
            lis[i]=con[i]=1;

            for(int j=0;j<i;j++){

                if(nums[i]>nums[j] ){
                    if(lis[i]==lis[j]+1)
                        con[i]+=con[j];

                    if( lis[i]<lis[j]+1){
                        lis[i]=lis[j]+1;
                        con[i]=con[j];
                    }
                }
            }

            if(lis[i]==currmax){
                count+=con[i];

             } else if(lis[i]>currmax){

                currmax=lis[i];
                count=con[i];
            }
        }
        return count;
    }
};