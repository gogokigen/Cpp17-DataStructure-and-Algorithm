#include <iostream>
#include <algorithm>
using namespace std;

// using #include <algorithm>
class Solution {

public:
    bool isSameByPermutation(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1 == s2 ? true : false;
    } 

};

// method 2
class Solution {

public:
    string strSort(string s) {
        int n = s.size(), counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }

    bool isSameByPermutation(string s1, string s2){
        if(s1.length() != s2.length()) return false;
        return strSort(s1) == strSort(s2) ? true : false;
    } 

};


int main(){

    Solution* sol = new Solution();
    cout<< "isSameByPermutation : " << sol->isSameByPermutation("abc", "cba") << endl;
    cout<< "isSameByPermutation : " << sol->isSameByPermutation("abc", "cbd") << endl;
    return 0;
}