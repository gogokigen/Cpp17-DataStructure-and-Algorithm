/*******************************************************************
* https://leetcode.com/problems/all-paths-from-source-to-target/
* Medium
* 
* Conception: 
*  1. backtracking
*
* Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1,
* find all possible paths from node 0 to node n - 1,
* and return them in any order.
*
* The graph is given as follows: graph[i] is a list of all nodes you can visit from node i
* (i.e., there is a directed edge from node i to node graph[i][j]).
*
*
* Key:
*  1. 
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
class Solution {
    vector<vector<int>> result;
    void helper(vector<vector<int>>& graph, vector<int>& path, int pos, int len){
        
        if( pos == len - 1){
            result.push_back(path);
            return;
        }
        
        for(auto& next:graph[pos]){
            path.push_back(next);
            helper(graph, path, next, len);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> path;
        path.push_back(0);
        helper(graph, path, 0, len);
        return result;
    }
};
