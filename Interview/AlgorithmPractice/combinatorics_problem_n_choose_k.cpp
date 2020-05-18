/*******************************************************************
* n-choose-k
* 
* Conception: 
*  1. 
*
* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
* In other words, one of the first string's permutations is the substring of the second string.
*
*
* References:
*  1. https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
*  2. https://leetcode.com/problems/unique-paths/discuss/251036/combinatorics-problem
*  3. https://leetcode.com/problems/unique-paths/discuss/388409/Classic-n-choose-k-with-explanation-(Python)
*
*******************************************************************/
// Program to calculate C(n ,k)  
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns value of Binomial Coefficient C(n, k)  
int binomialCoeff(int n, int k)  {  
    int res = 1;  
  
    if(k > n - k){
        k = n - k;
    }
    
    //C(6,2), n = 6, k = 2
    for(int i = 0; i < k; i++){
        res *= n - i;
        res /= i + 1;
    }

    return res;  
}  
  
// Driver Code 
int main(){  
    int n = 6, k = 2;  
    cout << "Value of C(" << n << ", " 
         << k << ") is " << binomialCoeff(n, k);  
    return 0;  
}  