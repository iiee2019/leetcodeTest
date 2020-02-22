void swap(int* nums,int index1,int index2){
    if(index1==index2){
        return ;
    }
    int tmp=nums[index1];
    nums[index1]=nums[index2];
    nums[index2]=tmp;
}
int firstMissingPositive(int* nums, int numsSize){
    int i,j;
    for(i=0;i<numsSize;i++){
        while(nums[i]<=numsSize&&nums[i]>0&&nums[nums[i]-1]!=nums[i]){
            swap(nums,nums[i]-1,i);
        }
    }
    for(j=0;j<numsSize;j++){
        if(nums[j]!=j+1){
            return j+1;
        }
    }
    return numsSize+1;
}
