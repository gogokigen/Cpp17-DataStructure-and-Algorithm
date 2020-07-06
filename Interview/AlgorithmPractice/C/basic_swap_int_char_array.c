

int my_swap_int(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int my_swap_ptr(char** x, char** y){
    char* tmp = *x;
    *x = *y;
    *y = tmp;
}

void my_swap_data(char *str1, char *str2) { 
  char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char)); 
  strcpy(temp, str1); 
  strcpy(str1, str2); 
  strcpy(str2, temp); 
  free(temp); 
}   
   

int main() {
    int int1 = 5;
    int int2 = 8;
    my_swap_int(&int1, &int2);
    printf("After int1: %d, int2: %d \n", int1 , int2 );
    
    char* A = "aa";
    char* B = "bb";
    my_swap_ptr(&A, &B);
    printf("After A: %s, B: %s \n", A , B );
    
    
    char str1[10] = "str1"; 
    char str2[10] = "str2str2"; 
    my_swap_data(str1, str2);
    printf("After str1: %s, str2: %s", str1 , str2 );

    return 0;

}