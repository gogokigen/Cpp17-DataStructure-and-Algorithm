/*******************************************************************
* https://leetcode.com/problems/01-matrix/
* Medium
* 
* Conception: 
*  1.
*
* Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
* The distance between two adjacent cells is 1.
*
*
* Example:
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.youtube.com/watch?v=aQGfOXQFFeo
*
*******************************************************************/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int l = matrix.size();
        int c = l ? matrix[0].size():0;
        
        vector<vector<int>> dir = {{0,1}, {0 ,-1}, {1, 0}, {-1, 0}};

        vector<vector<int>> ans(l, vector<int>(c , 0));
        queue<pair<int, int>> todo;
        for(int i = 0; i < l; ++i) {
            for(int j = 0; j < c; ++j) {
                if(matrix[i][j] == 0) todo.push({i,j});
                ans[i][j] = 0;
            }
        }


        while(!todo.empty()) {  
            pair<int, int> curr = todo.front();
            todo.pop();
            
            for(int k = 0; k < 4; k++){
                int y = curr.first + dir[k][0];
                int x = curr.second + dir[k][1];
                if(0 <= x && x < c && 0 <= y && y < l && matrix[y][x] == 1 && ans[y][x] == 0){
                    todo.push({y,x});
                    ans[y][x] += ans[curr.first][curr.second] + 1;
                }
            }
        }
        return ans;
    }
};