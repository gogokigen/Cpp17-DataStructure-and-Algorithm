#include <iostream>
#include <vector>
using namespace std;

class Solution {


public:
    bool isUnique(string testString){
        if(testString.size() == 0) return true;
        vector<bool> queue(256,false);
        for(int i = 0; i < testString.length(); i++){
            if(queue[testString[i]] == true){
                return false;
            } else {
                queue[testString[i]] = true;
            }
        }
        return true;
    } 

};

int main(){


    Solution* sol = new Solution();
    cout<< "isUnique? : " << sol->isUnique("abfrjts") << endl;
    cout<< "isUnique? : " << sol->isUnique("abfarjts") << endl;
    return 0;
}