/*******************************************************************
* https://leetcode.com/problems/h-index-ii/
* Medium
* 
* Conception: 
*  1. Binary search
*
* Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher,
* write a function to compute the researcher's h-index.
*
* According to the definition of h-index on Wikipedia: "A scientist has index h 
* if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
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
// binary search O(log n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        int mid = 0;
        while(l <= r){
            mid = l + ( r - l) /2;
            if(citations[mid] == n - mid){
                return n - mid;
            }else if (citations[mid] > n - mid){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return n - l;
    }
};

// O(n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for(int i = 0; i < citations.size();i++){
            if( n - i <= citations[i]) return n - i;
        }
        return 0;
    }
};