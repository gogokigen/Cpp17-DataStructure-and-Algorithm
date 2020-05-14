/*******************************************************************
* https://leetcode.com/problems/implement-trie-prefix-tree/
* Medium
* 
* Conception: 
*  1. Tree
*
* Implement a trie with insert, search, and startsWith methods.
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.youtube.com/watch?v=f48wGD-MuQw&t=311s
*
*******************************************************************/
class Trie {
private:
    struct TrieNode{
        TrieNode(): isWord(false), children(26, nullptr){}
        bool isWord;
        vector<TrieNode*> children;
        
        ~TrieNode(){
            for(TrieNode* child:children){
                if(child) delete child;
            }
        }
    };
    unique_ptr<TrieNode> dummy;
    TrieNode* find(string& word){
        TrieNode* p = dummy.get();
        for(char c:word){
            p = p->children[c-'a'];
            if(p == nullptr) break;
        }
        return p;
    }

public:
    /** Initialize your data structure here. */
    Trie():dummy(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = dummy.get();
        for(char c:word){
            if(p->children[c-'a'] == nullptr){
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = find(word);
        return tmp != nullptr && tmp->isWord == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */