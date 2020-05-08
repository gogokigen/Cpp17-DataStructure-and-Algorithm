/*******************************************************************
* https://leetcode.com/problems/check-if-it-is-a-straight-line/
* Easy
* 
* Conception: 
*  1. 
*
* You are given an array coordinates, coordinates[i] = [x, y],
* where [x, y] represents the coordinate of a point.
* Check if these points make a straight line in the XY plane.
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class Solution {
private:
    float checkSlope(vector<int>& x, vector<int>& y){
        return (float)(x[1] - y[1] )/(float)(x[0] - y[0]);
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() == 2) return true;
        
        if(coordinates[0][0] == coordinates[1][0]){ // vertical
            for(int i = 2; i < coordinates[0].size(); i++){
                if(coordinates[1][0] != coordinates[i][0]){
                    return false;
                }
                return true;
            }
        }
        
        float slope = checkSlope(coordinates[0], coordinates[1]);
        //cout << "slope: " << slope << endl;
        for(int i = 1; i < coordinates.size()-1; i++){
            //cout << slope << "," << checkSlope(coordinates[i], coordinates[i+1]) << endl;
            if(slope != checkSlope(coordinates[i], coordinates[i+1])){
                return false;
            }
        }
        return true;
    }
};