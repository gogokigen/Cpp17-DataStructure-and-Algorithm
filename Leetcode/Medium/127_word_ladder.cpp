/*******************************************************************
* https://leetcode.com/problems/word-ladder/
* Medium
* 
* Conception: 
*  1. 
*
* Given two words (beginWord and endWord), and a dictionary's word list,
* find the length of shortest transformation sequence from beginWord to endWord, such that:
*    Only one letter can be changed at a time.
*    Each transformed word must exist in the word list.
*
*
* Example:
*
* Key:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord ) == wordList.end()) return 0;

        unordered_set<string> visited(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);


        // Start BFS
        int steps = 0;
        while(!todo.empty()) {
            ++steps;
            int size = todo.size();
                    
            for(int i = 0; i < size; i++){
                string curr = todo.front();
                todo.pop();
                if(curr == endWord) {
                    return steps;
                }
            
                visited.erase(curr);
                for(int j = 0; j < curr.size(); j++){
                    char c = curr[j];
                    for(int k = 0; k < 26; k++){
                        curr[j] = 'a'+ k;
                        if(visited.find(curr) != visited.end()){
                            todo.push(curr);
                            visited.erase(curr);
                        }
                    }
                    curr[j] = c;
                }
            }
        }
        return 0;
    }
};

//TLE, but this version is great !!
class Solution {
    bool oneCharDiff(string w1, string w2){
        int diff = 0;
        for(int i = 0; i < w1.length(); i++){
            char c1 = w1[i], c2 = w2[i];
            if(c1 != c2){
                diff++;
            }
        }
        return diff == 1;
    }
    unordered_map<string, vector<string>> constructGraph(vector<string> wordList){
        unordered_map<string, vector<string>> graph;
        int n = wordList.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                string w1 = wordList[i], w2 = wordList[j];
                if(oneCharDiff(w1 , w2)){
                    //cout << "w1: " << w1 << ", w2: " << w2 << endl;
                    graph[w1].push_back(w2);
                    graph[w2].push_back(w1);
                    
                }
            }
        }
        //cout << "graph: " << graph.size() << endl;
        return graph;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord ) == wordList.end()) return 0;
        
        if(find(wordList.begin(), wordList.end(), beginWord ) == wordList.end()){
            wordList.push_back(beginWord);
        }
        unordered_map<string, vector<string>> graph = constructGraph(wordList);
        
        set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        
        int cost = 1;
        
        while(!q.empty()){
            int n_queue = q.size();
            //cout << n_queue << endl;
            for(int i = 0; i < n_queue; i++){
                string curr = q.front();
                //cout << "curr: " << curr << endl;
                q.pop();
                if(curr == endWord){
                    return cost;
                }
                
                for(auto neighbor : graph[curr]){
                    //cout << "neighbor: " << neighbor << endl;
                    if(visited.find(neighbor)  == visited.end() ){
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            cost++;
        }
        return 0;
    }
};
