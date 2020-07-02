#include <iostream>

using namespace std;

int my_strcmp(const char* s1, const char* s2){
    
    while( *s1 == *s2 && *s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
    }
    if(*s1 == '\0' && *s2 == '\0'){
        return 0;
    } else {
        return -1;
    }
}



//    if Return value < 0 then it indicates str1 is less than str2.
//    if Return value > 0 then it indicates str2 is less than str1.
//    if Return value = 0 then it indicates str1 is equal to str2.

int my_strncmp(const char* s1, const char* s2, int len_size){


    while( *s1 == *s2 && *s1 != 0 && len_size > 0){
        s1++;
        s2++;
        len_size--;
    }

   // if(*s1 == '\0' && len_size > 0){
   //     return -1;
   // } else if (*s2 == '\0' && len_size > 0){
   //     return 2;
   // }
    
    
    if ( len_size == 0 ){
        return 0;
    }else{
        return ( *s1 - *s2 );
    }
}

int main() {
    int test = my_strncmp("advccc", "advc", 8);

    cout << test << endl;
    return 0;

}
