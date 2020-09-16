//https://emn178.pixnet.net/blog/post/92129581

int max(int a, int b){
    int diff = a - b;
    int sign_bit= unsigned(diff) >> (sizeof(int) * 8 - 1);
    int array[] = {a, b};
    return array[sign_bit];
}