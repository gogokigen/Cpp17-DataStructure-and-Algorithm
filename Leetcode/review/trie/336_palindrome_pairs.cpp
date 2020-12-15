/*******************************************************************
* https://leetcode.com/problems/palindrome-pairs/
* Hard
* 
* Conception: 
*  1. Trie
*
* Given a list of unique words, return all the pairs of the distinct indices (i, j) in the given list,
* so that the concatenation of the two words words[i] + words[j] is a palindrome.
*
* Key:
*  1. 
*
* Reference:
*  1. https://leetcode.com/problems/palindrome-pairs/discuss/79202/Clean-C%2B%2B-implementation
*
*******************************************************************/
//Slower but easier
class Solution {
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

    /** Inserts a word into the trie. */
    void insert(TrieNode* root, string& word) {
        TrieNode* head = root;
        for(char& w: word){
            if(!head->children[w - 'a']){
                head->children[w - 'a'] = new TrieNode();
            }
            head = head->children[w - 'a'];
        }
        head->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(TrieNode* root, string word) {
        TrieNode* p = root;
        for(char& s:word){
            p = p->children[ s - 'a'];
            if(!p) return false;
        }
        return p && p->isWord;
    }

    bool isSubstringPalindrone(string str){
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i++] != str[j--]){
                return false;
            }
        }
        return true;
    }


public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> map_idxOfWord; //save idndex of words 
        
        //Construct Trie tree
        TrieNode* root = new TrieNode();

        for(int i = 0; i < words.size(); i++){
            
            string word = words[i];

            reverse(word.begin(), word.end());

            map_idxOfWord[word] = i ; // ctreat the reverse string and save it
            insert(root, word);
            reverse(word.begin(), word.end());
        }
        
        
        vector<vector<int>> ans;
        if(map_idxOfWord.count("")){ // special case for empty case
            for(int i = 0; i < words.size(); i++){
                if(words[i]!="" && isSubstringPalindrone(words[i])){
                    ans.push_back({map_idxOfWord[""], i});
                }
            }
        }

        for(int i = 0; i < words.size(); i++){
            string word = words[i];

            for(int j = 0; j < word.size(); j++){
                string left = word.substr(0,j);
                string right = word.substr(j);
                // find the reverse of right and find {its (the reverse of right) index == map_idxOfWord[left]}
                if(search(root, left) && isSubstringPalindrone(right) && map_idxOfWord[left] != i){
                    ans.push_back({i,map_idxOfWord[left]});
                }
                if(search(root,right) && isSubstringPalindrone(left) && map_idxOfWord[right] != i){
                    ans.push_back({map_idxOfWord[right],i});
                }
            }
        }
        return ans;
    }
};

// faster
class Solution {
private:
    vector<vector<int>> ans;
    struct TrieNode{
        int indexWord;
        bool isWord;
        vector<TrieNode*> children;
        
        TrieNode(): isWord(false), children(26, nullptr){}
        ~TrieNode(){
            for(TrieNode* child:children){
                if(child) delete child;
            }
        }
    };

    /** Inserts a word into the trie. */
    void insert(TrieNode* root, string word, int indexWord) {
        TrieNode* head = root;
        for(char& w: word){
            if(!head->children[w - 'a']){
                head->children[w - 'a'] = new TrieNode();
            }
            head = head->children[w - 'a'];
        }
        head->isWord = true;
        head->indexWord = indexWord;
    }

    /** Returns if the word is in the trie. */
    bool search(TrieNode* root, string word) {
        TrieNode* p = root;
        return p && p->isWord;
    }

    bool isSubstringPalindrone(string str){
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i++] != str[j--]){
                return false;
            }
        }
        return true;
    }


public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string,int> map_idxOfWord; //save idndex of words 
        
        //Construct Trie tree
        TrieNode* root = new TrieNode();
        int emptyIndex = -1;
        for(int i = 0; i < words.size(); i++){
            map_idxOfWord[words[i]] = i ;

            string word = words[i];
            reverse(word.begin(), word.end());
            insert(root, word, i);
            reverse(word.begin(), word.end());
        }
        
        
        vector<vector<int>> ans;
        if(map_idxOfWord.count("")){ // special case for empty case
            for(int i = 0; i < words.size(); i++){
                if(words[i]!="" && isSubstringPalindrone(words[i])){
                    ans.push_back({map_idxOfWord[""],i});
                }
            }
        }

        for(int i = 0; i < words.size() ; i++){
            string word = words[i];

            for(int j = 0; j < word; j++){
                string left = words[i].substr(0,j);
                string right = words[i].substr(j);
                if(search(root, left) && ispalindrome(right) && map_idxOfWord[left] != i){//
                    ans.push_back({i,map_idxOfWord[left]});
                }
                if(search(root,right) && ispalindrome(left) && map_idxOfWord[right] != i){// as discussed
                    ans.push_back({map_idxOfWord[right],i});
                }
            }
            
            helper(root, word, i);
        }
        return ans;
    }
};