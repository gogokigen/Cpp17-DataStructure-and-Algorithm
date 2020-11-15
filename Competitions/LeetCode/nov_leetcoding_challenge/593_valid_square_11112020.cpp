/*******************************************************************
* https://leetcode.com/problems/valid-square/
* Medium
* 
* Conception: 
*  1. 
*
* Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
* The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
* A valid square has four equal sides with positive length and four equal angles (90-degree angles).
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
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int> m;
        m[pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2)]++;
        m[pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2)]++;
        m[pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2)]++;
        m[pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2)]++;
        m[pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2)]++;
        m[pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2)]++;
        if(m.size() != 2|| m.count(0))return false;
        return true;
    }
};