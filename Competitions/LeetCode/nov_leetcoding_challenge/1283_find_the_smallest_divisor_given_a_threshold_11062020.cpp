/*******************************************************************
* https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
* Medium
* 
* Conception: 
*  1. 
*
* Given an array of integers nums and an integer threshold,
* we will choose a positive integer divisor and divide all the array by it and sum the result of the division.
* Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
* 
* Each result of division is rounded to the nearest integer greater than or equal to that element.
* (For example: 7/3 = 3 and 10/2 = 5).
*
* It is guaranteed that there will be an answer.
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
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        int ans;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int sum = 0;
            for(auto num: nums) {
                sum += ceil((float)(num)/(float)(mid));
            }
            if(sum <= threshold) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};