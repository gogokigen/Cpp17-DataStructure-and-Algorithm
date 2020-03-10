/*******************************************************************
* https://leetcode.com/problems/minimum-knight-moves/
* Medium
* 
* Conception: 
*  1. BFS: https://www.geeksforgeeks.org/level-order-tree-traversal/
*
* In an infinite chess board with coordinates
* from -infinity to +infinity, you have a knight at square [0, 0].
* A knight has 8 possible moves it can make, as illustrated below.
* Each move is two squares in a cardinal direction,
* then one square in an orthogonal direction.
*
* Constraints: |x| + |y| <= 300
*
*
* Example:
*
*
* Key:
*  1. Narrow down to 1st Quadrant
*
*******************************************************************/
#include <iostream>
#include <queue> // for queue
#include <set> // for set
using namespace std;


class Solution {
public:
    Solution(){};

    int minKnightMoves(int x, int y) {
        vector <vector<int>> direct = {{ 1, 2}, { 2, 1}, { 2, -1}, { 1, -2},
                                       { -1, -2}, { -2, -1}, { -2, 1}, { -1, 2}};
        
        queue<pair<pair<int, int>,int>> q; //{{x,y} , dist}
        q.push({{0,0}, 0});
        
        set<pair<int,int>> visited;
        visited.insert({0,0});
        
        x = abs(x); //Key! map to 1st Quadrant in order to reduce some steps
        y = abs(y); //Key! map to 1st Quadrant in order to reduce some steps
        int count = 0;
        while(q.empty() == false){

            cout << count << endl;
            pair<pair<int, int>,int> now = q.front();
            q.pop();
            
            int locateX = now.first.first;
            int locateY = now.first.second;
            int nowDist = now.second;
            
            if(locateX == x && locateY == y){
                return nowDist;
            }

            if (locateX < -2 ||locateY < -2) continue; //Key! {locateX, locateY} is not our consideration. reduce some steps
		    if (locateX > x+2 || locateY > y+2) continue; //Key! {locateX ,locateY} is not our consideration. reduce some steps

            for(int i = 0; i < direct.size(); i++){
                int newX = locateX + direct[i][0];
                int newY = locateY + direct[i][1];

                if (visited.find({newX , newY}) == visited.end()){ //can't find
                    visited.insert({newX , newY});
                    q.push({{newX , newY}, nowDist+1});
                }
                
            }
            ++count;
        }
        
        return 0;
    }
};

int main()
{
    //Test Cases
    //int x = 2, y = 1; //1: [0, 0] → [2, 1]
    //int x = 5, y = 5; //4: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
    int x = 270, y = -21; //135
    //int x = -2, y = 1; //1

    Solution* sol = new Solution;
    int ret;
    ret = sol->minKnightMoves(x ,y);

    cout << "result: " << ret << endl;

    return 0;
}