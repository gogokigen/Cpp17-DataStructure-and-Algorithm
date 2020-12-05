/*******************************************************************
* https://leetcode.com/problems/course-schedule/
* Medium
* 
* Conception: 
*  1. 
*
* There are a total of numCourses courses you have to take,
* labeled from 0 to numCourses-1.
*
* Some courses may have prerequisites, for example
* to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
*
* Given the total number of courses and a list of prerequisite pairs,
* is it possible for you to finish all courses?
*
*
* Key:
*  1. Topology sort
*  2. circle
*
* Explanation:
*
* References:
*  1. https://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/
*  2. https://class.coursera.org/algo-003/lecture/52
*  3. topological sort https://blog.techbridge.cc/2020/05/10/leetcode-topological-sort/
*
*******************************************************************/
//BFS: topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> order;
        
        //construct graph
        for(int i = 0; i < numCourses; i++){
            graph[i] = {};
            order[i] = 0;
        }

        //build the graph
        for(int i = 0; i < prerequisites.size(); i++){
            int preCource = prerequisites[i][1];
            int cource = prerequisites[i][0];
            
            //pre -> cources
            graph[preCource].push_back(cource);
            order[cource]++;
        }

        //find the sources which has no any dependency
        queue<int> sources;
        for(auto& p: order) {
            if(p.second == 0){
                sources.push(p.first);
            }
        }
        
        //generate the sequence of cources
        vector<int> sortedCourse;
        while(!sources.empty()){
            int intCource = sources.front();
            sources.pop();
            sortedCourse.push_back(intCource);
            
            for(auto& g:graph[intCource]){
                if(--order[g] == 0){
                    sources.push(g);
                }
            }
        }
        
        // If the size of topological order list is not equal to numCourses
        // Return false
        return sortedCourse.size() == numCourses;
    }
};

//DFS
class Solution {
private:
    vector<vector<int>> graph;
    bool dfs(int curr, vector<int>& visited){
        if(visited[curr] == -1) return false;
        if(visited[curr] == 1) return true;
        
        visited[curr] = 1;
        
        for(int& i:graph[curr]){
            if(dfs(i,visited)) return true;
        }
        visited[curr] = -1;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        
        for(auto& i: prerequisites){ // construct graph
            graph[i[0]].push_back(i[1]);
        }
        
        vector<int> visited(numCourses, 0);// 0: not yet, 1: vistiting, -1: visited
        
        for(int i = 0; i < numCourses; i++){
            if(dfs(i, visited)) return false;
        }
        return true;
    }
};

