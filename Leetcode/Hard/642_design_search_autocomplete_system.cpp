/*******************************************************************
* https://leetcode.com/problems/design-search-autocomplete-system/
* Hard
* 
* Conception: 
*  1. Trie
*
* Design Search Autocomplete System
*
* Key:
*  1. 
*
* Reference:
*  1. 
*
*******************************************************************/
class TrieNode {
public:
    vector<TrieNode*> children = vector<TrieNode*>(27, nullptr);
    bool is_word = false;
    int hot_level = 0;
};

class Comparator{
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b){
        if (a.second != b.second){
            return a.second > b.second;
        }else{
            return strcmp(a.first.c_str(), b.first.c_str()) < 0;
        }
    }
};

class AutocompleteSystem {
private:
    TrieNode* root = nullptr;
    string cur_sentence;
    TrieNode* cur = nullptr;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        for (int i = 0; i < sentences.size(); i++){
            AddWord(root, sentences[i], times[i]);
        }
        cur = root;
        cur_sentence = "";
    }
    
    void AddWord(TrieNode* root, const string& sentence, const int time){
        for(const auto& ch : sentence){
            if (ch >= 'a' && ch <= 'z'){
                if(root->children[ch - 'a'] == nullptr) root->children[ch - 'a'] = new TrieNode();
                root = root->children[ch - 'a'];
            }else if(ch == ' '){
                if(root->children[26] == nullptr) root->children[26] = new TrieNode();
                root = root->children[26];
            }
        }
        
        root->is_word = true;
        root->hot_level += time;
    }
    
    vector<pair<string, int>> FindAllMatch(TrieNode* cur){
        vector<pair<string, int>> res;
        FAM(cur, res, "");
        
        return res;
    }
    
    void FAM(TrieNode* cur, vector<pair<string, int>>& res, string so_far){
        if (cur == nullptr) return;
        if (cur->is_word) {
            res.push_back(make_pair(so_far, cur->hot_level));
        }
        
        for (int i = 0; i < cur->children.size() - 1; i++){
            if (cur->children[i]){
                char new_char = 'a' + i;
                FAM(cur->children[i], res, so_far + new_char);
            }
        }

        if (cur->children[26]){
            FAM(cur->children[26], res, so_far + ' ');
        }
    }
    
    vector<string> input(char c) {
        if (c == '#'){
            cur->is_word = true;
            cur->hot_level += 1;
            cur = root;
            cur_sentence.clear();
            return vector<string>();
        }else if (c == ' '){
            if (cur->children[26] == nullptr) cur->children[26] = new TrieNode();
            cur = cur->children[26];
        }else{
            if (cur->children[c - 'a'] == nullptr) cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur_sentence = cur_sentence + c;
        vector<pair<string, int>> match = FindAllMatch(cur);
        std::sort(match.begin(), match.end(), Comparator());
        vector<string> result;

        for(int i = 0; i < match.size(); i++){
            if (i >= 3) break;
            result.push_back(cur_sentence + match[i].first);
        }
        
        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */