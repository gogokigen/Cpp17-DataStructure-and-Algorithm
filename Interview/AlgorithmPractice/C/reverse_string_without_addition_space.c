void reverse(char* a){
    printf("init: %s \n", a);

    char* end_ptr = a;
    while( *end_ptr!= '\0'){
        end_ptr++;
    }
    end_ptr--;


    char* begin_ptr = a;
    char ch;
    while(begin_ptr < end_ptr) { 
        // swap character 
        ch = *end_ptr; 
        *end_ptr = *begin_ptr; 
        *begin_ptr = ch; 
  
        // update pointers positions 
        begin_ptr++; 
        end_ptr--; 
    } 

    printf("end: %s", a);
}


int main(){
    char str[100] = "GeeksForGeeks";
    char test[] = "GeeksForGeeks";
    reverse(test);

    return 0;
}