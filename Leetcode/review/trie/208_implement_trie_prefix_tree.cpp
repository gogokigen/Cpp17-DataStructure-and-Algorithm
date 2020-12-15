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
*  2. https://www.geeksforgeeks.org/trie-insert-and-search/
*
*******************************************************************/
class Trie {
private:
    struct TrieNode{
        bool isWord;
        vector<TrieNode*> children;
        
        TrieNode(): isWord(false), children(26, nullptr){}
        ~TrieNode(){
            for(TrieNode* child:children){
                if(child) delete child;
            }
        }
    };
    
    unique_ptr<TrieNode> dummy;
    TrieNode* find(string& source){
        TrieNode* p = dummy.get();
        for(char& s:source){
            p = p->children[s - 'a'];
            if(!p) break;
        }
        return p;
    }
    
public:
    /** Initialize your data structure here. */
    Trie(): dummy(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* head = dummy.get();
        for(char& w: word){
            if(!head->children[w - 'a']){
                head->children[w - 'a'] = new TrieNode();
            }
            head = head->children[w - 'a'];
        }
        head->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* head = find(word);
        return head && head->isWord == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */