#include <iostream>
#include <iomanip>
#include <arpa/inet.h>
using namespace std;

int main(){

    short int a = 0x1234;
    char *p = (char *)&a;
    
    cout << "*p=" << hex << setw(4) <<  *p << dec <<  endl;

    if(*p == 0x34){
        cout << "Little endian" << endl;
    } else if(*p == 0x12) {
        cout << "Big endian" << endl;
    } else {
        cout << "Unknow endian" << endl;
    }

    // solution 2
    int c = 0x12345678;
    int b = htonl(c);
    if (b == c){
        cout << "Big Endian" << endl;
    } else {
        cout << "Little Endian" << endl;
    }

    return 0;
}
