/*******************************************************************
* https://leetcode.com/problems/poor-pigs/
* Hard
* 
* Conception: 
*  1. 
*
* There are 1000 buckets, one and only one of them is poisonous,
* while the rest are filled with water. They all look identical.
* If a pig drinks the poison it will die within 15 minutes.
* What is the minimum amount of pigs you need to figure out which bucket is poisonous within one hour?
*
* Answer this question, and write an algorithm for the general case.
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
    int poorPigs(int b, int m, int t) {
        return ceil(log(b)/log((t/m) + 1));
    }
};