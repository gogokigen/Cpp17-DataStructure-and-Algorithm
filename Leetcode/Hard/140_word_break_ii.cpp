/*******************************************************************
* https://leetcode.com/problems/word-break-ii/
* Hard
*
* Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
* add spaces in s to construct a sentence where each word is a valid dictionary word.
* Return all such possible sentences.
*
* Example:
*
* Key:
*  1. 
*
* References:
*  1.
*
*******************************************************************/
class Trie{
public:
    Trie* children[26];
    string word;
    
    Trie() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
    } 
    
    Trie(vector<string>& wordDict){
        for(int i = 0; i < 26; i++) children[i] = NULL;
        
        for(auto& word: wordDict){
            add(word);
        }
    }
    
    void add(string& word){
        Trie* cur = this;
        
        for(int i = 0; word[i]; i++) {
            if(cur->children[word[i] - 'a'] == NULL){
                cur->children[word[i] - 'a'] = new Trie;
            }
            
            cur = cur->children[word[i] - 'a'];
        }
        
        cur->word = word;
    }
};


class Solution {
private:
    vector<string>* wordBreakUtil(string s, int start, Trie* root, vector<vector<string>*>& dp){
        if(dp[start] != NULL)
            return dp[start];
        
        vector<string>* ans = new vector<string>;
        
        Trie* cur = root;
        for(int i = start; i < s.length(); i++){
            cur = cur->children[s[i]-'a'];
            
            if(cur == NULL) break;
            
            if((cur->word).length()){
                vector<string>* lookAhead = wordBreakUtil(s, i + 1, root, dp);
                
                for(auto soln: *lookAhead){
                    (*ans).push_back(cur->word + (soln.length() == 0? "": " " + soln));
                }
            }
        }
        
        dp[start] = ans;
        
        return ans;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>*> dp(s.length() + 1, NULL);
        dp[s.length()] = new vector<string>(1, "");
        
        Trie* root = new Trie(wordDict);
        
        vector<string> ans = *wordBreakUtil(s, 0, root, dp);
        
        for(auto ptr: dp){
            if(ptr != NULL)
                delete ptr;
        }
        
        return ans;
    }
};


class Solution {
public:
    
    void populateSentence(string &s, int start, unordered_set<string> &dict, vector<bool> &dp, string curr, vector<string> &res) {
        if(start == s.size()) {
            string temp = curr.substr(0, curr.size()-1);
            res.push_back(temp);
            return;
        }
        
        //Recursive formulation
        //Try sll partitions
        
        int n = s.size();
        string t = "";
        for(int i = start; i < n; i++) {
            t += s[i];
            if(dict.find(t) == dict.end())
                continue;
            if(dp[i+1])
                populateSentence(s, i + 1, dict, dp, curr + t + " ", res);
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        
        unordered_set<string> dict;
        
        for(int i = 0; i < wordDict.size(); i++) 
            dict.insert(wordDict[i]);
        
        string t = "";
        
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for(int i = n-1; i > 0; i--) {
            t = "";
            for(int j = i; j < n; j++) {
                t += s[j];
                
                if(dict.find(t) == dict.end())
                    continue;
                
                if(dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        vector<string> res;
        populateSentence(s, 0, dict, dp, "",res);
        return res;
    }
};
