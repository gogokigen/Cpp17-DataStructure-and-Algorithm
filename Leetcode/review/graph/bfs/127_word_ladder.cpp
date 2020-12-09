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

