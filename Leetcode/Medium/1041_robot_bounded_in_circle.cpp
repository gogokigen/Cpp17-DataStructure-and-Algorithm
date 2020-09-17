/*******************************************************************
* https://leetcode.com/problems/robot-bounded-in-circle/
* Medium
* 
* Conception: 
*  1. 
*
* On an infinite plane, a robot initially stands at (0, 0) and faces north.
* The robot can receive one of three instructions:
*    "G": go straight 1 unit;
*    "L": turn 90 degrees to the left;
*    "R": turn 90 degress to the right.
*
* The robot performs the instructions given in order, and repeats them forever.
* Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
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
    bool isRobotBounded(string inst) {
        int x = 0, y = 0, dir = 0;
        const int arr[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto& i:inst){
            if( i == 'G'){
                x += arr[dir][0];
                y += arr[dir][1];
            }
            if( i == 'L') dir = ( 4 + dir - 1)%4;
            if( i == 'R') dir = ( dir + 1)%4;
        }
        if(x == 0 && y == 0) return true;
        return dir!=0;
    }
};