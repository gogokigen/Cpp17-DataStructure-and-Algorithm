/*******************************************************************
* https://leetcode.com/problems/longest-mountain-in-array/
* Medium
* 
* Conception: 
*  1. 
*
* You may recall that an array arr is a mountain array if and only if:
*    arr.length >= 3
*    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
*        arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
*        arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*
* Given an integer array arr, return the length of the longest subarray,
* which is a mountain. Return 0 if there is no mountain subarray.
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
/*
    int longestMountain(vector<int>& A) {
        const int N = A.size();
        vector<int> ups(N, 0), downs(N, 0);
        for(int i = 1; i < N; i++) if(A[i] > A[i-1]) ups[i] = ups[i-1]+1;
        int ans = 0;
        for(int i = N - 1; i >= 0; i--){
            if(i < N - 1 && A[i] > A[i+1]) downs[i] = downs[i+1]+1;
            if(ups[i] && downs[i]) ans = max(ans, ups[i] + downs[i] + 1);            
        }
        return ans;
    }
*/
public:
    int longestMountain(vector<int>& a) {
        int i,n=a.size(),res,l,h,ind,maxi=0;
        if(n == 0) return 0;

        for(i=1;i<n-1;i++) {
            if(a[i-1]<a[i] && a[i]>a[i+1]) {
                l = i-1;
                h = i+1;

                while( l > 0 && a[l] > a[l-1]) l--;

                while(h < n-1 && a[h] > a[h+1]) h++;

                maxi = max(maxi, h-l+1);
            }
        }
        return maxi;
    }
};