/*******************************************************************
* 
* Optimize recursion by Memoization
* 
* References: 
*  1. https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/
*
* Key:
*  1. Memoization
*  2. recursion
*
*******************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

// Fibonacci Series

class Solution {
public:
    Solution(){};

    int count = 0;
    // Method 1: recursion
    //time: 0.000111, count: 21891
    int fib_recursion(int n) { 
        count++;
        // Base case 
        if (n <= 1){
            return n;
        }

        // recursive calls
        return fib_recursion(n - 1) + fib_recursion(n - 2);
    }
    
    // Method 2: optimize recursion by memoization
    // time: 3e-06, count: 39
    int cache[1000];
    
    int fib_memoization(int n) { 
        count++;
        // Base case 
        if (n <= 1){
            return n;
        } 
        
        if (cache[n] != 0){
            return cache[n]; 
        } else {
            cache[n] = fib_memoization(n - 1) + fib_memoization(n - 2);
            return cache[n];
        }
    }
    
};

int main()
{
    clock_t start, stop;
    Solution* sol = new Solution;
    int ret = -1;

    //Test Cases
    start = clock();
    //ret = sol->fib_recursion(20);
    ret = sol->fib_memoization(20);
    stop = clock();
    cout << "time: " << double(stop - start) / CLOCKS_PER_SEC << endl;
    cout << "count: "<< sol->count << endl;

    return 0;
}