/*******************************************************************
* https://leetcode.com/problems/champagne-tower/
* Medium
* 
* Conception: 
*  1. 
*
* We stack glasses in a pyramid, where the first row has 1 glass,
* the second row has 2 glasses, and so on until the 100th row.
* Each glass holds one cup of champagne.
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
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(102,vector<double>(102,0));
        v[0][0]=poured;

        for(int i=0;i<query_row;i++){
            for(int j=0;j<=i;j++){
                double flow=(v[i][j]-1)/2.0;
                if(flow>0){
                    v[i+1][j]+=flow;
                    v[i+1][j+1]+=flow;
                }
            }
        }
        return min(1.0,v[query_row][query_glass]);
    }
};