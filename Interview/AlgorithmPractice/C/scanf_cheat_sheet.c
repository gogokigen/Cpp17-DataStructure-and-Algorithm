
int maxSubArray(int nums[], int len) {

    // don't do this
    //int len = sizeof(nums)/sizeof(nums[0]);
    if(len==0) return 0;
    if(len==1) return nums[0];


    int currSum = nums[0];
    int maxSum = nums[0];
    for(int i = 1; i < len; ++i) {
        if(nums[i] == EOF) break;
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}



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



    int array[5];
    printf("Input for numbers \n");
    while( i < 5){
        scanf("%d", &array[i]);
        if (array[i] == EOF) break;
        printf("%d \n",array[i]);
        i++;
    }
    int len = sizeof(array)/sizeof(array[0]);
    printf("len: %d \n", len);
    printf("maxSubArray: %d \n",maxSubArray(array,len));
    
    return 0;

}