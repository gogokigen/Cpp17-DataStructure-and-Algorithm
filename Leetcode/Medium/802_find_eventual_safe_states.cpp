/*******************************************************************
* https://leetcode.com/problems/find-eventual-safe-states/
* Medium
* 
* Conception: 
*  1. Graph finds a circle
*
* In a directed graph, we start at some node and every turn,
* walk along a directed edge of the graph.
* If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
*
* Now, say our starting node is eventually safe if and only if 
* we must eventually walk to a terminal node.
* More specifically, there exists a natural number K so that for any choice of where to walk,
* we must have stopped at a terminal node in less than K steps.
*
* Which nodes are eventually safe?  Return them as an array in sorted order.
*
*
* Example:
* 
* Key:
*  1. 
*
* References:
*  1. https://zxi.mytechroad.com/blog/graph/leetcode-802-find-eventual-safe-states/
*
*******************************************************************/
class Solution {
private:
    enum State {UNKNOWN, VISITING, SAFE, UNSAFE};

    State dfs(vector<vector<int>>& graph, int curr, vector<State>& states){
        if(states[curr] == VISITING) return states[curr] = UNSAFE;
        if(states[curr] != UNKNOWN) return states[curr]; //SAFE or UNSAFE
        
        states[curr] = VISITING;
        
        //check next is safe or unsafe
        for(int next:graph[curr]){
            if(dfs(graph, next, states) == UNSAFE) return states[curr] = UNSAFE;
        }
        return states[curr] = SAFE;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<State> states(graph.size(), UNKNOWN);
        vector<int> ans;
        
        //traverse
        for(int i = 0; i < graph.size(); i++){
            if(dfs(graph, i, states) == SAFE){
                ans.push_back(i);
            }
        }
        return ans;
    }
};