/*******************************************************************
* 
* Practice: Quick Sort
* 
* References: 
*  1. https://www.youtube.com/watch?v=PgBzjlCcFvc
*  2. https://www.geeksforgeeks.org/quick-sort/
*  3. Analyze: https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/analysis-of-quicksort
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
    int helper(vector<int>&list, int start, int end ){
        int pivot = list[end];
        int i = start-1; //index of smaller number
        for(int j = start; j < end; j++){
            if(list[j] < pivot){
                i++;
                swap(&list[i], &list[j]);
            }
        }
        swap(&list[i+1], &list[end]);
        return i + 1;
    }

    void quickSort(vector<int> &list, int start, int end ){
        if(start < end){
            int partition = helper(list, start, end);

            quickSort(list, start, partition - 1);
            quickSort(list, partition+1, end);
        }
    }

};

int main(){
    //Test Cases
    vector<int> list = { 10, 9, 8, 2 , 4 , 6, 7};


    Solution* sol = new Solution();

    sol->quickSort(list, 0, (list.size()-1));

    for(auto& i:list){
        cout << i << ", ";
    }

    return 0;
}