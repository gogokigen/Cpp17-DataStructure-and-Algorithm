/*******************************************************************
* https://leetcode.com/problems/unique-binary-search-trees/
* Medium
* 
* Conception: 
*  1. f(3) = f_l(2)*f_r(0) + f_l(1)*f_r(1) + f_l(0)*f_r(2)
*     f(4) = f_l(3)*f_r(0) + f_l(2)*f_r(1) + f_l(1)*f_r(2) + f_l(0)*f_r(3)
*          = f(3)*f_r(0) + f_l(2)*f_r(1) + f_l(1)*f_r(2) + f_l(0)*f(3)
*
* Given n,
* how many structurally unique BST's (binary search trees) that store values 1 ... n?
*
*
* Example:
* 
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int numTrees(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j < i; j++){
                ans[i] += ans[j] * ans[i - j - 1];
            }
        }
        return ans[n];
    }
};