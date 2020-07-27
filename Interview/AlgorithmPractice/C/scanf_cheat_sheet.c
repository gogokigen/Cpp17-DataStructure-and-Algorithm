int main() {



    int input;
    int a,b,c; 
    printf("Input numbers：\n");
    scanf("%d%d%d%d",&a,&b,&c,&input);
    printf("%d,%d,%d,%d/n", a, b, c, input);


    char str[10];
    printf("Input for string \n");
    //scanf("%s",string); //space is not accepted
    scanf("%[^\n]",str);
    //scanf("%9s",str);
    printf("%s \n",str);

    char ch1; 
    printf("Input for ch1:n"); 
    scanf("%c",&ch1); 

    return 0;

}