#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;


int main(int argc, char const *argv[]){

    vector<int> ret;
    int casesNumber = 0;
    scanf("%d", &casesNumber);
    vector<vector<int>> array;
    for (int i = 0; i < casesNumber; i++){
        int N = 0;
        int B = 0;
        scanf("%d%d", &N, &B);

        vector <int> array;
        for (int j = 0; j < N; j++){
            int tmp;
            scanf("%d", &tmp);
            array.push_back(tmp);
        }
        
        sort(array.begin(), array.end()); 
        int count = 0;
        for(int j = 0; j < array.size(); j++){
            if (B - array[j] >= 0){
                count++;
                B = B - array[j];
            }
        }
        ret.push_back(count);
    }

    // output
    for (int i = 1; i <= casesNumber; ++i) {
        int n = ret[i - 1];
        cin >> n;  // read n and then m.
        cout << "Case #" << i << ": " << n<< endl;
    }

    return 0;
}