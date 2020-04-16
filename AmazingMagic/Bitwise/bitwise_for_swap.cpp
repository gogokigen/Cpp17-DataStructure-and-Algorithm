/*******************************************************************
* Bitwise for swap
* 
* Reference: 
*  1. https://betterexplained.com/articles/swap-two-variables-using-xor/
*
* Explanation:
*  x  = x^y
*  y' = x^y = (x^y)^y = x^(y^y) = x
*  x' = x^y = x^(x^y) = (x^x)^y = y
*
*
* Advanced:
*  1. 
*
*******************************************************************/
#include <iostream> 
using namespace std; 

void swap_xor(int* x, int* y){
    *x = *x ^ *y;
    *y = *y ^ *x;
    *x = *x ^ *y;
}

// main function to perform division of two numbers
int main(void){
    int x = 22;
    int y = -7;
    int* px = &x;
    int* py = &y;
    cout <<"Input x: "<< *px << ", y: "<<*py<<endl;
    swap_xor(px,py);
    cout <<"Output x: "<< *px << ", y: "<<*py<<endl;
	return 0;
}