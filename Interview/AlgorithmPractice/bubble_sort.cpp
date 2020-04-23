/*******************************************************************
* 
* Practice: Bubble Sort
* 
* References: 
*  1. https://www.youtube.com/watch?v=nmhjrI-aW5o
*
* Key:
*  1. 
*
*******************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(){};
    void swap(int* a, int* b)  {  
        int t = *a;  
        *a = *b;  
        *b = t;  
    }  

    void bubbleSort(vector<int> &list){
        
        for(int i = 0; i < list.size() - 1; i++){
            for(int j = 0; j < list.size() - i - 1; j++){
                if( list[j] > list[j+1]){
                    swap(&list[j],&list[j+1]);
                }
            }
        }
    }

};

int main(){
    //Test Cases
    vector<int> list = { 10, 9, 8, 2 , 4 , 6, 7};


    Solution* sol = new Solution();

    sol->bubbleSort(list);

    for(auto& i:list){
        cout << i << ", ";
    }

    return 0;
}