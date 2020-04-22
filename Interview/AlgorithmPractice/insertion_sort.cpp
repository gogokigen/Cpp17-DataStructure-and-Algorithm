/*******************************************************************
* 
* Practice: Insertion Sort
* 
* References: 
*  1. https://www.youtube.com/watch?v=OGzPmgsI-pQ
*  2. https://www.geeksforgeeks.org/insertion-sort/
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
    void insertionSort(vector<int> &list){
        int n = list.size();

        for(int i = 1; i < n; i++){
            int key = list[i];
            int j = i - 1;
            while( j >=0 && list[j] > key){
                //larger will move back
                list[j+1] = list[j];
                j--;
            }
            //key will move to correct position
            list[j+1] = key;
        }
    }

};

int main(){
    //Test Cases
    vector<int> list = { 10, 9, 8, 2 , 4 , 6, 7};


    Solution* sol = new Solution();

    sol->insertionSort(list);

    for(auto& i:list){
        cout << i << ", ";
    }

    return 0;
}