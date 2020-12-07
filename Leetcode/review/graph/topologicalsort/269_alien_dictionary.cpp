/*******************************************************************
* https://leetcode.com/problems/alien-dictionary/
* Hard
* 
* Conception: 
*  1. 
*
* There is a new alien language that uses the English alphabet.
* However, the order among letters are unknown to you.
*
* You are given a list of strings words from the dictionary,
* where words are sorted lexicographically by the rules of this new language.
*
* Derive the order of letters in this language, and return it.
* If the given input is invalid, return "".
* If there are multiple valid solutions, return any of them.
*
*
* Key:
*  1. Topology sort
*
* Explanation:
*
* References:
*  1. topological sort https://blog.techbridge.cc/2020/05/10/leetcode-topological-sort/
*
*******************************************************************/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> degree;
        
        //construct graph
        for(auto word:words){
            for(char c:word){
                graph[c] = vector<char>();
                degree[c] = 0;
            }
        }

        //build the graph
        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i], w2 = words[i + 1];
            
            int len = min(w1.length(), w2.length());
            for(int j = 0; j < len; j++){
                char parent = w1[j], child = w2[j];
                if(parent != child){
                    graph[parent].push_back(child);
                    degree[child]++;
                    break;
                }
                
                if( j == len - 1&& w1.length() > w2.length() ) return "";
            }
        }

        //find the sources which has no any dependency
        queue<char> sources;
        for(auto& p: degree) {
            if(p.second == 0){
                sources.push(p.first);
            }
        }
        
        //generate the sequence of cources
        string order;
        while(!sources.empty()){
            char curr = sources.front();
            sources.pop();
            order += curr;
            
            for(auto& g:graph[curr]){
                if(--degree[g] == 0){
                    sources.push(g);
                }
            }
        }
        
        // If the size of topological order list is not equal to numCourses
        // Return false
        return (order.length() == degree.size()) ? order:"";
    }
};
