int climbStairs(int n){
    //int*  dp=(int *)malloc((n+1)*sizeof(int));
    int dp[n+1];
    if(n==1||n==0){
        return 1;
    }
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
