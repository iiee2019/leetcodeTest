bool hasAlternatingBits(int n){
    long int tmp=(n^(n>>1));
    return (tmp&(tmp+1))==0;
}
