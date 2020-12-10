/*******************************************************************
* https://leetcode.com/problems/shortest-distance-from-all-buildings/
* Hard
* 
* Conception: 
*  1. 
*
* You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
* You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
*    Each 0 marks an empty land which you can pass by freely.
*    Each 1 marks a building which you cannot pass through.
*    Each 2 marks an obstacle which you cannot pass through.
*
*
* Key: BFS
*
* Explanation:
*
* References:
*  1. https://leetcode.com/problems/shortest-distance-from-all-buildings/discuss/915979/C%2B%2B-clean-solution-by-puting-BFS-in-a-separat
*
*******************************************************************/
class Solution {
private:
    void bfs(vector<vector<int>>& grid, int y, int x, vector<vector<int>>& dist, vector<vector<int>>& reached){
        int l = grid.size(), c = l > 0 ? grid[0].size():0;
        
        vector<vector<int>> visited(l, vector<int> (c, 0));
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        queue<pair<int,int>> q;
        q.push({y , x});

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++){
                pair<int,int> here = q.front();
                q.pop();
                for(int k = 0; k < 4; k++){
                    int ky = here.first+dir[k][0];
                    int kx = here.second+dir[k][1];
                    if(0 > ky || ky >= l || 0 > kx || kx >= c || visited[ky][kx] == 1 || grid[ky][kx] != 0){
                        continue;
                    }else{
                        q.push({ky,kx});
                        visited[ky][kx] = 1;
                        reached[ky][kx]++; // noted for the number of reached buildings
                        dist[ky][kx]+= level;
                    }
                }
            }
        }
        
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int l = grid.size(), c = l ? grid[0].size():0;
        
        vector<vector<int>> dist(l, vector<int> (c, 0));
        vector<vector<int>> reached(l, vector<int> (c, 0));

        int num_of_building = 0;
        for(int j = 0; j < l; j++){
            for(int i = 0; i < c; i++){
                if(grid[j][i] == 1){
                    num_of_building++; //how many buildings
                    bfs(grid, j, i, dist, reached);
                }
                
            }
        }

        int res = INT_MAX;
        for(int j = 0; j < l; j++){
            for(int i = 0; i < c; i++){
                if(num_of_building == reached[j][i] && dist[j][i] < res){
                    
                    res = dist[j][i];
                }
                
            }
        }
        return res == INT_MAX? -1 : res;
    }
};