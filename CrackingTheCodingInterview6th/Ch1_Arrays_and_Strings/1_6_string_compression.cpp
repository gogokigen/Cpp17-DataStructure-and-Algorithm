#include <iostream>

using namespace std;

class Solution {

public:
    string compress(string& chars) {
        string ret;
        int count = 0;
        for(int j = 1; j <= chars.size(); j++) {
            count++;

            if(j == chars.size() || chars[j] != chars[j - 1]) {
                ret += chars[j-1];
                ret += to_string(count);
                count = 0;
            }

        }
        return ret;
    }

};



int main (){

    Solution *sol = new Solution ();
    string test ="aafgyttreee";
    cout << "compress: " << sol->compress (test) << endl;
    return 0;
}
