/*******************************************************************
* 
* Binary Search compared with iterator and recurssion
* 
* References: 
*  1. https://techdifferences.com/difference-between-recursion-and-iteration-2.html
*
* Key:
*  1. iterator
*  2. recurssion
*
*******************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


class Solution {
public:
    Solution(){};

    // Method 1: iterator, count: 3
    /*
    int binarySearch(vector<int> &list, int target){
        int left = 0;
        int right = list.size();
        int mid = left + (right - left) /2;
        
        while(left < right){
            cout << count << " left " << left << "; right " << right << endl;
            count++;
            if (list[mid] == target) return mid;
            if (list[mid] > target){
                right = mid;
            }else{
                left = mid + 1;
            }
            mid = left + (right - left) /2;
            
            if(count == 10) break;
        }
        
        return -1;
    }
    */
    
    // Method 2: recurrsion
    int binarySearchRecurrision(int left, int right, int target, vector<int> &list){
        int mid = left + (right - left) /2;

        cout << count << " left " << left << "; right " << right << endl;
        count++;
        if (list[mid] == target) return mid;
        if (list[mid] > target){
            return binarySearchRecurrision(left , mid, target, list);
        }else{
            return binarySearchRecurrision(mid + 1 , right, target, list);
        }
            
        if(count == 10) break;

        return -1;
        
    }

    int binarySearch(vector<int> &list, int target){
        int left = 0;
        int right = list.size();
        int ret = -1;
        ret = binarySearchRecurrision(left , right, target, list);
        
        return ret;
    }

};

int main()
{
    clock_t start, stop;
    //Test Cases
    // find : 333
    vector<int> targetList = { 0, 1 , 4 , 5, 8, 9, 88, 101, 102, 103, 234, 256, 333, 444, 555, 666, 999, 777777};


    Solution* sol = new Solution;

    start = clock();
    ret = sol->binarySearch(targetList, 333);
    stop = clock();

    cout << double(stop - start) / CLOCKS_PER_SEC <<endl;


    return 0;
}