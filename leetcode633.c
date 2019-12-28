bool judgeSquareSum(int c){
    int num=(int)sqrt(c);
    long long int left=0;
    long long int right=num+1;
    while(left<=right){
        long long int tmp=left*left+right*right;
        if(tmp<c)
            left++;
        else if(tmp>c)
            right--;
        else    
            return true;
    }
    return false;
}
