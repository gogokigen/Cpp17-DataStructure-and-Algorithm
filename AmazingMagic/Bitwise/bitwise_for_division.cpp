/*******************************************************************
* Bitwise for division
* 
* Reference: 
*  1. https://stackoverflow.com/questions/5284898/implement-division-with-bit-wise-operator
*  2. https://www.techiedelight.com/perform-division-two-numbers-without-using-division-operator/
*
* Key:
*  1. 
*
* Pros:
*  1. 
*
* Advanced:
*  1. 
*
*******************************************************************/
#include <iostream> 
using namespace std; 

// Function to perform division (x / y) of two numbers x and y without 
// using division operator in the code
int divide(int x, int y){
	// handle divisibility by 0
	if (y == 0){
		cout <<"Error!! Divisible by 0"<<endl;
		return 0;
	}

	// store sign of the result
	int sign = 1;
	if (x * y < 0){
		sign = -1;
	}

	// convert both dividend and divisor to positive
	x = abs(x), y = abs(y);

	// initialize quotient by 0
	int quotient = 0;

	// loop till dividend x is more than the divisor y
	while (x >= y){
	   x = x - y;		// perform reduction on dividend
	   quotient++;		// increase quotient by 1
	}

	cout <<"Remainder is " << x << endl;

	return sign * quotient;
}

int divide_bit(int x, int y){
	// handle divisibility by 0
	if (y == 0){
		cout <<"Error!! Divisible by 0"<<endl;
		return 0;
	}

	// store sign of the result
	int sign = 1;
	if (x * y < 0){
		sign = -1;
	}

	// convert both dividend and divisor to positive
	x = abs(x), y = abs(y);

	unsigned mask = 1;
	unsigned quotient = 0;

	while (y <= x){
		y <<= 1;
		mask <<= 1;
	}

	while (mask > 1){
		y >>= 1;
		mask >>= 1;
		if (x >= y){
			x -= y;
			quotient |= mask;
		}
	}

	cout <<"Remainder is " << x << endl;

	return sign * quotient;
}

// main function to perform division of two numbers
int main(void){
	int dividend = 22;
	int divisor = -7;
    int quotient = divide_bit(dividend, divisor);
	cout <<"Quotient is " << quotient << endl;

	return 0;
}