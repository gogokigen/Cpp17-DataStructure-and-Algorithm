/*******************************************************************
* https://www.geeksforgeeks.org/perfect-number/
* 
* Conception: 
*  1. 
*
* A number is a perfect number if is equal to sum of its proper divisors.
*
* Key:
*  1. 
*
* Reference:
*  1. https://www.geeksforgeeks.org/perfect-number/
*
*******************************************************************/
bool isPerfectNumber(long long int num){
    long long int sumDiv = 1;
    
    for(long long int i = 2; i*i <= num; i++){
        if( num % i == 0){
            if( i*i != num){
                sumDiv += i + num/i;
            }else {
                sumDiv += i;
            }
        }
    }
    //definition of perfect number
    if(sumDiv == num && num != 1) return true;
    
    return false;
}