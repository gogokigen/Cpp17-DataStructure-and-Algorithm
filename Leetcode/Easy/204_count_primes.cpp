/*******************************************************************
* https://leetcode.com/problems/count-primes/
* Easy
* 
* Conception: 
*  1. 
*
* Count the number of prime numbers less than a non-negative number, n.
*
*
* Example:
* 
* Key:
*  1. 
*
* References:
*  1. 
*
*******************************************************************/
//faster
class Solution {
public:
    int countPrimes(int n) {

        if( n <= 2 ) return 0;
        vector<bool> primes( n + 1, true);
        int ret = 0;
        for(int i = 2; i*i <= n; i++){
            if(primes[i] == true){
                for(int j = i*i; j <= n; j+=i){
                    primes[j] = false;
                }
            }
        }
        
        for(int i = 2; i < n; i++){
            if( primes[i] == true){
                ret++;
            }
        }
        return ret;
    }
};
//slow
class Solution {
private:
    bool checkPrime(int n){
        for(int i = 2; i*i <= n; i++){
            if( n%i == 0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {

        if( n <= 2 ) return 0;

        int ret = 0;
        for(int i = 2; i < n; i++){
            if(checkPrime(i)){
                ret++;
            }
        }
        return ret;
    }
};