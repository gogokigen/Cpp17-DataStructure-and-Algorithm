/*******************************************************************
* https://leetcode.com/problems/paint-fence/
* Easy
* 
* Conception: 
*  1. https://www.youtube.com/watch?v=deh7UpSRaEY
*
* There is a fence with n posts, each post can be painted with one of the k colors.
* You have to paint all the posts such that no more than two adjacent fence posts have the same color.
* Return the total number of ways you can paint the fence.
* Note:
* n and k are non-negative integers.
*
*
* Example:
*
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
    int numWays(int n, int k) {
        if(n==0 || k ==0) return 0;
        if(n==1 ) return k;

        int same[n];
        int diff[n];
        diff[1] = k*(k-1);
        same[1] = k;
        for(int i = 2; i < n; i++){
            int tmp = diff[i - 1];
            diff[i] = (same[i-1] + diff[i-1]) * (k - 1);
            same[i] = tmp * 1;
        }
        
        return diff[n-1] + same[n -1];
    }
};