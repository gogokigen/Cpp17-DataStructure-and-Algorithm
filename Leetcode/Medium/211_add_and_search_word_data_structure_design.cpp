/*******************************************************************
* https://leetcode.com/problems/add-and-search-word-data-structure-design/
* Medium
* 
* Conception: 
*  1. tries #208
*
* Design a data structure that supports the following two operations:
*
* void addWord(word)
* bool search(word)
*
* search(word) can search a literal word or a regular expression string containing
* only letters a-z or ..
* A . means it can represent any one letter.
*
*
* Example:
*
* Key:
*  1.
*
* References:
*  1. https://www.geeksforgeeks.org/trie-insert-and-search/
*
*******************************************************************/
class WordDictionary {
private:
    WordDictionary *child[26] = {};
    bool isend = false;
public:
    /** Initialize your data structure here. */
    WordDictionary() { }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *node = this;
        for(char& w:word){
            int ind = w -'a';
            if(!node->child[ind]){
                node->child[ind] = new WordDictionary();
            }
            node = node->child[ind];
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        WordDictionary *node = this;
        return search_util(word,node);
    }
    bool search_util(string word, WordDictionary *node) {
        for(int i = 0; i < word.size() && node; i++){
            if(word[i] == '.'){
                WordDictionary *tmp = node;
                for(int j=0; j < 26; j++){
                    node = tmp->child[j];
                    if(search_util(word.substr(i+1),node)){
                        return true;
                    }
                }
            } else {
                int ind = word[i]-'a';
                if(!node->child[ind]){
                    return false;
                }
                node = node->child[ind];
            }
            
        }
        return (node && node->isend == true );
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */