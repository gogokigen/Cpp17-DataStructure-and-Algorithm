/*******************************************************************
* 
* Practice: Sort Stack
* 
* References: 
*  1. https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    Solution(){};
/* increasing:
  cache
  | 3|
  |23|
  |31|
  |34|
  |92|
  |98|
  ---
*/
    stack<int> sortStack(stack<int>& input){

        stack<int> cache;
        while(!input.empty()){
            int tmp =  input.top();
            input.pop();
            while(!cache.empty() && cache.top() < tmp){
                input.push(cache.top()); // input becomes a tmp stack.
                cache.pop();
            }
            cache.push(tmp); //bigger number pushed into cache
        }
        return cache;
    }
};

int main() {
    stack<int> input; 
    input.push(34); 
    input.push(3); 
    input.push(31); 
    input.push(98); 
    input.push(92); 
    input.push(23); 

    Solution* sol = new Solution;
    stack<int> retStack = sol->sortStack(input);
    while (!retStack.empty()){ 
        cout << retStack.top()<< " "; 
        retStack.pop(); 
    } 

    return 0;
}