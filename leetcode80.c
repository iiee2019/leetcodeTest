int removeDuplicates(int* nums, int numsSize){
    if(numsSize<=2){
        return numsSize;
    }
    int sp=1;
    for(int fp=2;fp<numsSize;fp++){
        if(nums[fp]!=nums[sp-1]){
            nums[++sp]=nums[fp];
        }
    } 
    return sp+1;
}
