#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int singleNumber(int* nums, int numsSize){
    int res=0;
    for(int i=0;i<numsSize;i++){
        res=res^nums[i]; 
    }
    return res;
}

int main(){
   int arr[]={2,2,1};
   int* ptr=arr;
   int res=singleNumber(ptr,3);
   printf("%d\n",res);
   return 0; 
}
