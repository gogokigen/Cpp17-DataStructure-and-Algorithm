/*******************************************************************
* https://leetcode.com/problems/minimum-height-trees/
* Medium
* 
* Conception: 
*  1. 
*
* A tree is an undirected graph in which any two vertices are connected by exactly one path.
* In other words, any connected graph without simple cycles is a tree.
*
* Given a tree of n nodes labelled from 0 to n - 1,
* and an array of n - 1 edges where edges[i] = [ai, bi] indicates that
* there is an undirected edge between the two nodes ai and bi in the tree,
* you can choose any node of the tree as the root.
* When you select a node x as the root, the result tree has height h.
* Among all possible rooted trees, those with minimum height (i.e. min(h)) are called minimum height trees (MHTs).
*
* Return a list of all MHTs' root labels. You can return the answer in any order.
* The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*
*
* Example:
*
* Key:
*  1. topology sort
*
* References:
*  1.
*
*******************************************************************/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            return {0};
        }
        vector<vector<int>>graph(n);
        vector<int>degree(n,0);
        for(vector<int>&edge: edges){
            //undirected graph
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            
            //note for degree
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                //the last leaf node
                q.push(i);
            }
        }
        while(n > 2){
            int sz = q.size();
            n -= sz;
            
            //q saved the nodes which are far from the center.
            for(int i = 0; i < sz; i++){
                int t = q.front();
                q.pop();
                for(int j = 0; j < graph[t].size(); j++){
                    degree[graph[t][j]]--;
                    if(degree[graph[t][j]] == 1){
                        // closed to center
                        q.push(graph[t][j]);
                    }
                }
            }  
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
