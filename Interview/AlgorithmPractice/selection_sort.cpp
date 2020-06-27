/*******************************************************************
* 
* Practice: Selection Sort
* 
* References: 
*  1. https://www.youtube.com/watch?v=xWBP4lzkoyM
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

    void selectionSort(vector<int> &list){
        int len = list.size();
        
        for(int i = 0; i < len; i++){
            int key = list[i];
            int pos = i;
            for(int j = i + 1; j < len; j++){
                if( list[j] < key){
                    key = list[j];
                    pos = j;
                }
            }
            swap(&list[pos],&list[i]);
        }
    }

};

int main(){
    //Test Cases
    vector<int> list = { 10, 9, 8, 2 , 4 , 6, 7};


    Solution* sol = new Solution();

    sol->selectionSort(list);

    for(auto& i:list){
        cout << i << ", ";
    }

    return 0;
}