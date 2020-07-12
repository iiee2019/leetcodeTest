int findLengthOfLCIS(int* nums, int numsSize){
    if(nums==NULL||numsSize==0){
        return 0;
    }
    int dp[numsSize];
    int  res=1;
    int i;
    dp[0]=1;
    for(i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]){
            dp[i]=dp[i-1]+1;
        }else{
            dp[i]=1;
        }
        if(dp[i]>res){
            res=dp[i];
        }      
    }
    return res;
}
