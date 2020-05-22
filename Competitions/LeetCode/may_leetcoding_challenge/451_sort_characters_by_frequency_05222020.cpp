/*******************************************************************
* https://leetcode.com/problems/sort-characters-by-frequency/
* Medium
* 
* Conception: 
*  1. 
*
* Given a string, sort it in decreasing order based on the frequency of characters.
*
*
* Key:
*  1. 128 chars
*
* Explanation:
*
* References:
*  1. 
*
*******************************************************************/
//Method 1
class Solution {
private:
public:
    string frequencySort(string s) {
        map<char, int> f;
        for(char i:s){
            f[i]++;
        }
        
        sort(s.begin(), s.end(), [&f](char a, char b){
            return f[a] > f[b] ||( f[a] == f[b] && a > b);
        });
        
        return s;
    }
};

// with bind
using namespace std::placeholders;
class Solution {
private:
    static bool sortRule(map<char, int>& f, char a, char b){
        return f[a] > f[b] ||( f[a] == f[b] && a > b);
    }
public:
    string frequencySort(string s) {
        map<char, int> f;
        for(char i:s){
            f[i]++;
        }
        
        sort(s.begin(), s.end(), bind(sortRule, f, _1, _2));
        
        return s;
    }
};

//Method 2
class Solution {
public:
    string frequencySort(string s) {
        array<int, 128> f{0};
        for(char i:s){
            ++f[i];
        }
        
        sort(s.begin(), s.end(), [&f](char a, char b){
            return f[a] > f[b] ||( f[a] == f[b] && a > b);
        });
        return s;
    }
};