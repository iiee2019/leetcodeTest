typedef struct {
    int lenght;
    int* newNums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj=(NumArray*)malloc(sizeof( NumArray));
    if(!obj){
        return NULL;
    }
    obj->newNums=nums;
    obj->lenght=numsSize;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
  int sum=0;
  for(int index=i;index<=j&&index<obj->lenght;index++){
      sum+=(*obj).newNums[index];
  }
  return sum; 
}

void numArrayFree(NumArray* obj) {
    free(obj);
    //obj=NULL;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
