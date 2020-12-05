/*******************************************************************
* https://leetcode.com/problems/course-schedule-ii/
* Medium
* 
* Conception: 
*  1. 
*
* There are a total of n courses you have to take labelled from 0 to n - 1.
* Some courses may have prerequisites, for example,
* if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.
*
* Given the total number of courses numCourses and a list of the prerequisite pairs,
* return the ordering of courses you should take to finish all courses.
*
* If there are many valid answers, return any of them.
* If it is impossible to finish all courses, return an empty array.
*
* Key:
*  1. Topology sort
*  2. circle
*
* Explanation:
*
* References:
*  1. topological sort https://blog.techbridge.cc/2020/05/10/leetcode-topological-sort/
*
*******************************************************************/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        if (sortedCourse.size() == numCourses){
            return sortedCourse;
        }else{
            return {};
        }
    }
};