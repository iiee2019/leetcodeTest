int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0||numsSize==1){
        return numsSize;
    }
    int len=0;  
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]!=nums[i+1]){
            nums[len++]=nums[i];
        }
    }
    nums[len++]=nums[numsSize-1];
    return len;
}
