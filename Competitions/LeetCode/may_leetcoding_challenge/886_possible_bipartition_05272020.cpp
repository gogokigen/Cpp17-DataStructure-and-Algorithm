/*******************************************************************
* https://leetcode.com/problems/possible-bipartition/
* Medium
* 
* Conception: 
*  1. 
*
* Given a set of N people (numbered 1, 2, ..., N),
* we would like to split everyone into two groups of any size.
* 
* Each person may dislike some other people, and they should not go into the same group. 
*
* Formally, if dislikes[i] = [a, b],
* it means it is not allowed to put the people numbered a and b into the same group.
*
* Return true if and only if it is possible to split everyone into two groups in this way.
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