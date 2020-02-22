/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize=2;
    int *ptr=(int *)malloc(2*sizeof(int));
    ptr[0]=0;
    ptr[1]=0;
    for(int i=0;i<numsSize-1;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                ptr[0]=i;
                ptr[1]=j; 
            }
        }
    }    
    return ptr;
}
