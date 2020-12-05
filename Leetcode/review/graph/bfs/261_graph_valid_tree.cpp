/*******************************************************************
* hhttps://leetcode.com/problems/graph-valid-tree/
* Medium
* 
* Conception: 
*  1. 
*
* Given n nodes labeled from 0 to n-1 and a list of undirected edges
* (each edge is a pair of nodes),
* write a function to check whether these edges make up a valid tree.
*
*
* Key:
*  1. Topology sort
*  2. circle
*
* Explanation:
*
* References:
*  1. topological sort https://blog.techbridge.cc/2020/05/10/leetcode-topological-sort/
*  2. https://leetcode.com/problems/graph-valid-tree/discuss/716414/O(n)-BFS-DFS-and-Union-Find-solutions-and-some-thoughts
*
*******************************************************************/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<vector<int>> graph(n, vector<int>());
        // build graph adjacency list
        for(auto& e: edges){
            graph[e[0]].push_back(e[1]);
            // since graph is bi-directional
            graph[e[1]].push_back(e[0]);
        }
        
        //find the sources which has no any dependency
        queue<int> sources;
        sources.push(0);
        set<int> seen;
        seen.insert(0);


        //generate the sequence of cources
        while(!sources.empty()){
            int node = sources.front();
            sources.pop();
            
            for(auto& nbhd:graph[node]){
                if(seen.find(nbhd) != seen.end()){
                    //have never seen
                    continue;
                }
                seen.insert(nbhd);
                sources.push(nbhd);
            }
        }
        
        // If the size of topological order list is not equal to numCourses
        // Return false
        return seen.size() == n;
    }
};