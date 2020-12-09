/*******************************************************************
* https://leetcode.com/problems/walls-and-gates/
* Medium
* 
* Conception: 
*  1. 
*
* You are given a m x n 2D grid initialized with these three possible values.
*    -1 - A wall or an obstacle.
*    0 - A gate.
*    INF - Infinity means an empty room.
*
* Fill each empty room with the distance to its nearest gate.
* If it is impossible to reach a gate, it should be filled with INF.
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
    void wallsAndGates(vector<vector<int>>& rooms) {
        int l = rooms.size(), c  = l ? rooms[0].size() : 0;
        vector<pair<int,int>> offsets{{0 , 1} , { 0, -1}, { 1, 0}, {-1, 0}};

        int GATE = 0, WALL = -1, ROOM = numeric_limits<int>::max();

        queue<pair<int, int>> todo;
        // Put all gates into queue
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < c; ++j) {
                if(rooms[i][j] == GATE) todo.push({i,j});
            }
        }


       // Start BFS
        int steps = 0;
        while(!todo.empty()) {                        
            for(int size = todo.size()-1; size >= 0; --size) {
                pair<int, int> cur = todo.front();
                todo.pop();

                if(rooms[cur.first][cur.second] == ROOM) {
                    rooms[cur.first][cur.second] = steps;
                }

                if(rooms[cur.first][cur.second] != WALL) {
                    // Traverse neighbor
                    for(int i = 0; i < offsets.size(); ++i) {
                        cur.first += offsets[i].first;
                        cur.second += offsets[i].second;

                        if(isValid(cur, l, c) && rooms[cur.first][cur.second] == ROOM) {
                            todo.push(cur); 
                        }

                        cur.first -= offsets[i].first;
                        cur.second -= offsets[i].second;
                    }
                }
           }

            ++steps;
        }
    }

private:
    bool isValid(const pair<int, int>& cur, const int& m, const int& n) {
        return cur.first >= 0 && cur.first < m && cur.second >= 0 && cur.second < n;
    }

};
