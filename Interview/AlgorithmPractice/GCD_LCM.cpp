#include <iostream>

using namespace std;

class Solution {
public:
    Solution(){};
    int GCD(int a, int b){
        int t = 0;
        while( b != 0){
            t = b;
            b = a % b;
            a = t;
        }
        
        return a;
    }

    int LCM(int a, int b){
        
        return (a*b/GCD( a, b));
    }
};

int main(){


    Solution* sol = new Solution();
    cout << "GCD( 99, 22): " << sol->GCD( 99, 22) << endl;
    cout << "LCM( 99, 22): " << sol->LCM( 99, 22) << endl;
    return 0;
}