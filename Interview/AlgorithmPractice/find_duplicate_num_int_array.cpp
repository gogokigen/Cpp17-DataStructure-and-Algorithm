#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


class Solution {
public:
    Solution(){};

    vector<int> findDuplicateNum(vector<int>& array){
        if(array.size() == 0) return {};
        
        set<int> cache;
        vector<int> ans;
        for(int& i:array){
            if(!cache.count(i)){
                cache.insert(i);
            }else{
                ans.push_back(i);
            }
        }
        
        return ans;
    }

    vector<int> findDuplicateNum(vector<int>& array){
        if(array.size() == 0) return {};
        
        sort(array.begin(), array.end());
        vector<int> ans;
        int j = 0;
        for(int i = 0; i + 1 < array.size(); i++){
            j = i;
            if(array[i] == array[i + 1]){
                ans.push_back(array[i]);
                j = i + 1;
                while(array[j] == array[j + 1]){
                    j++;
                }
                i = j - 1;
            }
        }
        
        return ans;
    }
};

int main(){
    //Test Cases
    
    vector<int> array = { 0, 1, 3, 6, 7, 4, 3, 7};
    Solution* sol = new Solution;
    vector<int> ans = sol->findDuplicateNum(array);

    for(int& a:ans){
        cout << a << endl;
    }

    return 0;
}
