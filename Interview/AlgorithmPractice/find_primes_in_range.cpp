#include <iostream>
#include <vector>
using namespace std;

vector<int> findPrime(int low, int high){
    vector<int> ret;
    if(high > low && high >= 2){
        if ( low <= 2){
            ret.push_back(2);
        }
        for(int x = low; x <= high; x++){
            for(int y = 2; y <= x; y++){
               if( x%y == 0){ 
                break;
               }else if ( x == y+1){
                   ret.push_back(x);
               }
             }
        }
    }else if (high > low && low >= 2){

        if (high <= 2){
            ret.push_back(2);
        }
        for(int x= high; x <= low; x++){
            for(int y = 2; y <= x; y++){
                if( x%y == 0){
                    break;
                } else if ( x == y+1){
                    ret.push_back(x);
                }
            }
        }
    }else {
        cout << "Error arange, or No prime numbers.";
    }
    return ret;
}

vector<int> findPrime(int low, int n){
    vector<int> ans;

    if( low < 2 ) return {};
    vector<bool> primes( n + 1, true);
    int ret = 0;
    for(int i = low; i*i <= n; i++){
        if(primes[i] == true){
            for(int j = i*i; j <= n; j+=i){
                primes[j] = false;
            }
        }
    }
    
    for(int i = low; i < n; i++){
        if( primes[i] == true){
            ret++;
            ans.push_back(i);
        }
    }
    return ans;

}

int main(){
    vector<int> ans = findPrime(2, 16);
    
    for(int& i:ans){
        cout << i << " ";
    }
    cout<< endl;
    return 0;
}
