/*******************************************************************
* https://leetcode.com/problems/paint-house/
* Easy
* 
* Conception: 
*  1. Bottom-Up
*
* There are a row of n houses,
* each house can be painted with one of the three colors: red, blue or green.
* The cost of painting each house with a certain color is different.
* You have to paint all the houses such that no two adjacent houses have the same color.
*
* The cost of painting each house with a certain color is represented by a n x 3 cost matrix.
* For example, costs[0][0] is the cost of painting house 0 with color red;
* costs[1][2] is the cost of painting house 1 with color green, and so on...
* Find the minimum cost to paint all houses.
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
    int minCost(vector<vector<int>>& costs) {
        if(costs.size()==0) return 0;
        
        for (int t = costs.size() -2 ; t >= 0; t--){
            costs[t][0] += min(costs[t + 1][1], costs[t + 1][2]);
            costs[t][1] += min(costs[t + 1][0], costs[t + 1][2]);
            costs[t][2] += min(costs[t + 1][0], costs[t + 1][1]);
        }
        
        return min(costs[0][0], min(costs[0][1], costs[0][2]));
    }
};