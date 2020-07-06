#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    Solution(){};
    void calculateChars(string& test){
        map<char, int> table;
        for(auto& c:test){
            table[c] += 1;
        }
        
        for(auto& i:table){
            cout <<"char " << i.first << ", times: " << i.second << endl;
        }
    }

};

int main(){


    Solution* sol = new Solution;
    string test1 = "abccbbbbjdoela";
    sol->calculateChars(test1);

    return 0;
}