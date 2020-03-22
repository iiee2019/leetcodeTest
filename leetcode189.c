void rotate(int* nums, int numsSize, int k){
    int i,j;
    if(k>numsSize){
        k=k%numsSize;
    }
    for(i=0,j=numsSize-k-1;i<j;i++,j--){  //倒置前numsSize-k个元素
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    for(i=numsSize-k,j=numsSize-1;i<j;i++,j--){ //倒置后k个元素
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
    for(i=0,j=numsSize-1;i<j;i++,j--){ //整个数组进行倒置
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
    }
}
