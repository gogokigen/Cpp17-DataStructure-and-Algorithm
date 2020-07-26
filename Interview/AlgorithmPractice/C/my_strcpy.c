//https://www.techiedelight.com/implement-strcpy-function-c/
#include <stdio.h>

char* my_strcpy(char* dest, const char* source){
    
    if(dest == NULL){
        return NULL;
    }

    char* ptr = dest;
    while( *dest != '\0'){
        dest++;
    }
    dest--;

    while( *source != '\0'){
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';
    return ptr;
}

int main() {
    char dest[26] = "afghjkk";
    char* test = my_strcpy(dest, "advc");

    printf("result: %s", test);
    return 0;

}