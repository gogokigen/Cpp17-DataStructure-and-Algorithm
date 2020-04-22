/*******************************************************************
* 
* Practice: Merge Sort
* 
* References: 
*  1. https://www.youtube.com/watch?v=JSceec-wEyw
*  2. https://www.youtube.com/watch?v=RZK6KVpaT3I
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

    void merge(vector<int>&list, int start, int end , int mid){
        int L_N = mid - start + 1;
        int R_N = end - mid;
        
        vector<int> L(L_N, 0);
        vector<int> R(R_N, 0);

        for(int i = 0; i < L_N; i++){
            L[i] = list[start + i];
        }
        for(int j = 0; j < R_N; j++){
            R[j] = list[ mid + 1 + j];
        }

        int i = 0, j = 0, k = start;
        while( i < L_N && j < R_N){
            if(L[i] <= R[j]){
                list[k] = L[i];
                i++;
            } else {
                list[k] = R[j];
                j++;
            }
            k++;
        }
        
        while( i < L_N){
            list[k] = L[i];
            i++;
            k++;
        }
        
        while( j < R_N){
            list[k] = R[j];
            j++;
            k++;
        }

    }

    void mergeSort(vector<int> &list, int start, int end ){
        if(start < end){
            int mid = start + (end - start) / 2;

            mergeSort(list, start, mid);
            mergeSort(list, mid+1, end);
            merge(list, start, end, mid);
        }
    }

};

int main(){
    //Test Cases
    vector<int> list = { 10, 9, 8, 2 , 4 , 6, 7};


    Solution* sol = new Solution();

    sol->mergeSort(list, 0, list.size()-1);

    for(auto& i:list){
        cout << i << ", ";
    }

    return 0;
}