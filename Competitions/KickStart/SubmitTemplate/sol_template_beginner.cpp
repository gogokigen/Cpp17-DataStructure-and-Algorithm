// headers
#include<iostream>
#include<vector>
#include <bits/stdc++.h> 

using namespace std;


int main(int argc, char const *argv[]){

    //for iutput
    vector<int> ret;
    
    // generally, 1st line is the number of cases.
    int casesNumber = 0;
    scanf("%d", &casesNumber);



    //Method 1: Save whole inputs in containers
    // declare {container} array;
    for (int i = 0; i < casesNumber; i++){

        //
        //save all input to array
        //

    }

    //
    //computing logic
    //
    //save answaer
    //



    //Method 2: A case, calculate once, then next case ...
    for (int i = 0; i < casesNumber; i++){

        //put out the data of i case
        vector <int> array;
        for (int j = 0; j < N; j++){
            int tmp;
            scanf("%d", &tmp);
            array.push_back(tmp);
        }


        //
        //computing logic
        //

        //save answaer
        ret.push_back(count);
    }




    // output
    for (int i = 1; i <= casesNumber; ++i) {
        int n = ret[i - 1];
        cin >> n;
        cout << "Case #" << i << ": " << n<< endl;
    }

    return 0;
}