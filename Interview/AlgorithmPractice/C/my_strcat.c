char* my_strcat(char *dest, const char *src){
    
    int i,j;
    for (i = 0; dest[i] != '\0'; i++){
        ;
    }

    for (j = 0; src[j] != '\0'; j++){
        dest[i+j] = src[j];
    }

    dest[i+j] = '\0';
    return dest;
}


char* my_strcat(char *dest, const char *src){
    char *rdest = dest;

    while (*dest)
      dest++;
    while (*dest++ = *src++)
      ;
    return rdest;
}

int main(){

    char a[10] = "abs";
    char b[10] ="idiidd";
    printf("%s", my_strcat(a, b));

    return 0;
}