#include <stdio.h>



int my_strcmp(const char* s1, const char* s2){
    
    while( *s1 == *s2 && *s1 != '\0' && *s2 != '\0'){
        s1++;
        s2++;
    }
    if(*s1 == '\0' && *s2 == '\0'){
        return 0;
    } else {
        return *s1 - *s2;
    }
}


int main() {

    printf("result: %d\n", my_strcmp("advc", "advc"));
    printf("result: %d", my_strcmp("advcssss", "advc"));
    return 0;

}