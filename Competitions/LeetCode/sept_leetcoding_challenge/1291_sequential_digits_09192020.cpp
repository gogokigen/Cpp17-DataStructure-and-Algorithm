/*******************************************************************
* https://leetcode.com/problems/sequential-digits/
* Medium
* 
* Conception: 
*  1. 
*
* An integer has sequential digits if and only if
* each digit in the number is one more than the previous digit.
*
* Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
*
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1. https://leetcode.com/problems/sequential-digits/discuss/853506/C++-dfs-solution-bfs-solution-and-iterator-solution.
*
*******************************************************************/
class Solution {
    vector<int> ans;
public:
    vector<int> sequentialDigits(int low, int high) {
        for (int i = 1; i <= 9; ++i) {
            dfs(i, i, low, high);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
    
    void dfs(int n, int last, int low, int high) {
        if (n > high) {
            return;
        }

        if (n >= low && n <= high) {
            ans.push_back(n);
        }

        if (last == 9) {
            return;
        }

        dfs(n * 10 + last + 1, last + 1, low, high);
    }
};