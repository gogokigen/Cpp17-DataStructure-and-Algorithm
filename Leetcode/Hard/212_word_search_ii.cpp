/*******************************************************************
* https://leetcode.com/problems/word-search-ii/
* Hard
* 
* Conception: 
*  1. 
*
* Given a 2D board and a list of words from the dictionary, find all words in the board.
*
* Each word must be constructed from letters of sequentially adjacent cell,
* where "adjacent" cells are those horizontally or vertically neighboring.
* The same letter cell may not be used more than once in a word.
*
* Example:
*
* Key:
*  1. tries
*
* References:
*  1. https://leetcode.com/problems/word-search-ii/discuss/712902/C%2B%2B-68-ms-Trie-and-Backtrack
*  2. https://leetcode.com/problems/implement-trie-prefix-tree/
*
*******************************************************************/
class TrieNode {
    friend class Solution;
private:
    bool isWord;
    vector<TrieNode*> children;

    TrieNode(): isWord(false), children(26, nullptr){}

    ~TrieNode(){
        for(TrieNode* child:children){
            if(child) delete child;
        }
    }
public:

};


class Solution {
    
public:
    int N, M;
    const vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    vector<string> findWords(vector<vector<char>>& board, const vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<string> ans;
        string s;
        
        N = board.size();
        M = board[0].size();
        
        for (const string& w : words){
            InsertTrie(w, root);
        }
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                s = "";
                if (root->children[board[i][j] - 'a'])
                    s += board[i][j], Helper(board, i, j, s, root->children[board[i][j] - 'a'], ans);
            }
        }
        return ans;
    }
    
    /** Inserts a word into the trie. */
    void InsertTrie(string word, TrieNode* root) {
        for(char c:word){
            if(root->children[c-'a'] == nullptr){
                root->children[c - 'a'] = new TrieNode();
            }
            root = root->children[c - 'a'];
        }
        root->isWord = true;
    }
    
    inline bool InRange(const int& r, const int& c) {
        return r >= 0 && r < N && c >= 0 && c < M;
    }

    void Helper(vector<vector<char>>& board, int& r, int& c, string& word, TrieNode* root, vector<string>& ans){
        if (root->isWord){
            ans.push_back(word);
            root->isWord = false;
        }
        
        char initial = board[r][c];
        int curr_r, curr_c;
        board[r][c] = '!';
        
        for (int i = 0; i < 4; i++){
            curr_r = r + dir[i][0], curr_c = c + dir[i][1];
            
           if (InRange(curr_r, curr_c) && isalpha(board[curr_r][curr_c])
                && root->children[board[curr_r][curr_c] - 'a']){
                word += board[curr_r][curr_c];
                Helper(board, curr_r, curr_c, word, root->children[board[curr_r][curr_c] - 'a'], ans);
                word.pop_back();
            }
        }
        
        board[r][c] = initial;
    }
};