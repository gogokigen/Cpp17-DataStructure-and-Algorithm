#include <iostream>

using namespace std;

class Solution{
public:
    void my_reverse(string test){
        int len = test.length();
        int i = 0, j = len - 1;
        while( i < j){
            char tmp = test[i];
            test[i] = test[j];
            test[j] = tmp;
            i++;
            j--;
        }
        cout << "result: " << test << endl;
    }
};

int main(){

    Solution* sol = new Solution;
    sol->my_reverse("abcgefrt");

    return 0;
}