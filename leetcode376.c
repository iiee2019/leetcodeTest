#define MAX(a,b) ((a)>(b))?(a):(b)
int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize==0||nums==NULL){
        return 0;
    }
    if(numsSize<2){
        return 1;
    }
    int dp[numsSize][2];
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<numsSize;i++){
        dp[i][0]=1;
        dp[i][1]=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i][0]=MAX(dp[i][0],dp[j][1]+1);
            }else if(nums[i]<nums[j]){
                dp[i][1]=MAX(dp[i][1],dp[j][0]+1);
            }
        }   
    }
    int res=1;
    for(int i=1;i<numsSize;i++){
        int tmp=MAX(dp[i][0],dp[i][1]);
        res=MAX(tmp,res);
    }
    return res;
}
