/*******************************************************************
* https://leetcode.com/problems/evaluate-division/
* Medium
* 
* Conception: 
*  1. 
*
* You are given an array of variable pairs equations and an array of real numbers values,
* where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
* Each Ai or Bi is a string that represents a single variable.
*
* You are also given some queries,
* where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
*
* Return the answers to all queries.
* If a single answer cannot be determined, return -1.0.
*
* Note: The input is always valid.
* You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
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
    unordered_map<string,int> seen;
    double dfs(unordered_map<string, set<pair<string,double>>> &graph, string a, string b){
        if(a == b) return 1.0;
        if(seen[a]) return -1;
        seen[a] = 1;
        for(auto to: graph[a]){
            double go = dfs(graph, to.first, b);
            if(go != -1)
                return to.second*go;
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, set<pair<string,double>>> graph;
        
        for(int i = 0; i < equations.size(); i++){
            auto node = equations[i];
            graph[node[0]].insert({node[1], values[i]});
            graph[node[1]].insert({node[0], 1.0/values[i]}); // weight = 1.0/values[i]}
        }
        
        vector<double> ans;
        
        for(auto& q: queries){
            double res = 0;
            if(graph.find(q[0]) == graph.end() || graph.find(q[1]) == graph.end())
                res = -1.0;
            else {
                seen.clear();
                res = dfs(graph, q[0], q[1]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
