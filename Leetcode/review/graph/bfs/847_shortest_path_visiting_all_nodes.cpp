/*******************************************************************
* https://leetcode.com/problems/shortest-path-visiting-all-nodes/
* Hard
* 
* Conception: 
*  1. 
*
* An undirected,
* connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.
*
* graph.length = N, and j != i is in the list graph[i] exactly once,
* if and only if nodes i and j are connected.
*
* Return the length of the shortest path that visits every node.
* You may start and stop at any node, you may revisit nodes multiple times,
* and you may reuse edges.
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
/* num = 5
[1] 0->1
[0,2,4] 1->0/2/4
[1,3,4] 2->1/3/4
[2] 3->2
[1,2] 4->1/2
*/
    int shortestPathLength(vector<vector<int>>& graph) {
        set <tuple<int, int, int>> visited;
        queue<tuple<int,int,int>> queue;
        
        int g_num = graph.size();
        int ans = 0;
        for(int i = 0; i < g_num; i++){
            visited.insert({i , 1 << i, 1});
            queue.push({i , 1 << i, 1});
        }
        while(!queue.empty()){
            int q_num = queue.size();
            
            for(int k = 0; k < q_num; k++){
                auto [id, bitmap, visited_num] = queue.front(); //id, bitmp, n_vis
                queue.pop();
                if(visited_num == g_num) return ans;
                
                for(int& nbhd:graph.at(id)){
                    tuple<int, int, int> tmp; 
                    int mask = (1 << nbhd); 
                    if( bitmap & mask){
                        tmp = { nbhd, bitmap, visited_num};
                    }else{
                        tmp = { nbhd, bitmap|(1 << nbhd), visited_num + 1};
                    }
                    if(!visited.count(tmp)){ //tmp hasn't been visited
                        visited.insert(tmp); 
                        queue.push(tmp);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
