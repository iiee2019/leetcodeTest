int getSum(int a, int b){
    unsigned long  carry=0;
    while(b!=0){
        int carry=a&b;
        a=a^b;
        b=(unsigned int)carry<<1;
    }
    return a;
}
