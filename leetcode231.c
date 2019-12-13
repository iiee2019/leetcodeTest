bool isPowerOfTwo(int n){
    unsigned long num=(unsigned long) n;
    return num&&!(num&(num-1));
}
