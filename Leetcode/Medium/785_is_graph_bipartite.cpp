/*******************************************************************
* https://leetcode.com/problems/is-graph-bipartite/
* Medium
* 
* Conception: 
*  1. 
*
* Given an undirected graph, return true if and only if it is bipartite.
*
* Recall that a graph is bipartite
* if we can split it's set of nodes into two independent subsets A and B such that
* every edge in the graph has one node in A and another node in B.
*
* Example:
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. https://www.youtube.com/watch?v=VlZiMD7Iby4
*
*******************************************************************/
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // save as edges
        vector<vector<int>> g(N);
        for(auto d:dislikes){
            g[d[0] - 1].push_back(d[1] - 1);
            g[d[1] - 1].push_back(d[0] - 1);
        }
        
        vector<int> color(N, 0); // 0: unknow, 1: blue, -1: red
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(color[i] != 0) continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty()){
                int pos = q.front();
                q.pop();
                for(auto nbh:g[pos]){
                    if(color[nbh] == color[pos]) return false;
                    if(color[nbh] != 0) continue;
                    
                    color[nbh] = -color[pos];
                    q.push(nbh);
                }
            }
        }
        return true;
    }
};