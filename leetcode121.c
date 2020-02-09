int Max(int a,int b){
    if(a>b){
        return a;}
    else{
        return b;}
}
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0){
        return 0;}
    int dp[pricesSize][2];

    for(int i=0;i<pricesSize;i++){
        if(i-1==-1){
            dp[i][0]=0;
            dp[i][1]=-prices[i];
            continue;
        }
        dp[i][0]=Max(dp[i-1][0],dp[i-1][1]+prices[i]);
        dp[i][1]=Max(dp[i-1][1],-prices[i]);
    }
    return dp[pricesSize-1][0];
}
