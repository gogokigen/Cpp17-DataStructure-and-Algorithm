#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int k = 10;
    int a = 3,b = 5, c = 7, x = 1;
    queue<int> q3, q5, q7;
    vector<int> ans;
    ans.push_back(x);
    for(int i = 1; i < k; i++){
        q3.push(x*3);
        q5.push(x*5);
        q7.push(x*7);
        x = min(q3.front(), min(q5.front(), q7.front()));
        if(x == q3.front()){
            q3.pop();
        }
        if(x == q5.front()){
            q5.pop();
        }
        if(x == q7.front()){
            q7.pop();
        }
        ans.push_back(x);
    }
    for(int& i : ans){
        cout << i << endl;
    }
    
    return 0;
}