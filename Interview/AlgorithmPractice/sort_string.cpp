#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

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

int main(){

    cout << strSort("elloyywgtaorld") << endl;

    return 0;
}