//https://www.geeksforgeeks.org/compute-the-minimum-or-maximum-max-of-two-integers-without-branching/
#include <stdio.h>



int max(int x, int y){
    
    // if ( x - y ) >> (sizeof(int) * 8  - 1) == 0, x - y is positive.
    // if ( x - y ) >> (sizeof(int) * 8  - 1) == 1, x - y is negative.
    return x - ((x - y) & (( x - y ) >> (sizeof(int) * 8  - 1)));
}

int min(int x, int y){
    
    // if ( x - y ) >> (sizeof(int) * 8  - 1) == 0, x - y is positive.
    // if ( x - y ) >> (sizeof(int) * 8  - 1) == 1, x - y is negative.
    return y + ((x - y) & (( x - y ) >> (sizeof(int) * 8  - 1)));
}

int main() {

    printf("max( 3, -9): %d\n", max( 3, -9));
    printf("min( 3, -9): %d\n", min( 3, -9));
    return 0;

}
