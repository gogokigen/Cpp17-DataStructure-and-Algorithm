/*******************************************************************
* https://leetcode.com/problems/two-city-scheduling/
* Easy
* 
* Conception: 
*  1. 
*
* There are 2N people a company is planning to interview.
* The cost of flying the i-th person to city A is costs[i][0],
* and the cost of flying the i-th person to city B is costs[i][1].
*
* Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
*
*
* Example:
* 
* Key:
*  1. Sorting is increasing
*  2. To minimise the costs,
*     send n persons with the smallest price_A - price_B to the city A, and the others to the city B.
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(), costs.end(), [](vector<int>&a, vector<int>& b){
                   return (a[0] - a[1] < b[0] - b[1]); 
               }
            );
        
        int l = costs.size() / 2;
        
        int ret = 0;
        for(int i = 0; i < l; i++){
            ret += costs[i][0] + costs[i + l][1];
        }
        
        return ret;
    }
};