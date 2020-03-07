int numTreesOfRes(int n,int* nums){
    if(n==0||n==1){
        nums[n]=1;
        return 1;
    }
    int numTree = 0;
    for(int i = 1; i < n + 1; i++) { 
        int tmp = 0;
        int leftTreeNum;
        int rightTreeNum;
        if(nums[i-1] == -1) { 
            leftTreeNum = numTreesOfRes(i - 1, nums);
            nums[i-1] = leftTreeNum; 
        } else {
            leftTreeNum = nums[i-1];
        }
        if(nums[n-i] == -1) {
            rightTreeNum = numTreesOfRes(n - i, nums);
            nums[n-i] = rightTreeNum; 
        } else {
            rightTreeNum = nums[n-i];
        }
        tmp = leftTreeNum * rightTreeNum;
        numTree = tmp + numTree;
    }
    return numTree;
}
int numTrees(int n){
  int *nums=(int *)malloc(sizeof(int)*(n+1));
  for(int i=0;i<n+1;i++){
      nums[i]=-1;
  }
  int res=numTreesOfRes(n,nums);
  free(nums);
  return res;
}
