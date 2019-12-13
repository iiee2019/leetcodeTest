int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int lengthOfLIS(int* nums, int numsSize){
    int* dp=(int*)malloc(numsSize*sizeof(int));
     for(int i=0;i<numsSize;i++){
        dp[i]=1;
    }
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<i;j++){
             if(nums[j]<nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res=0;
    for(int i=0;i<numsSize;i++){
        res=max(res,dp[i]);
    }
    return res;
}
