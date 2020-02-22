/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>
 int cmp(const void *a , const void *b ) {
     return *(int *)a -*(int *)b;
 }
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    if(nums1Size==0||nums2Size==0){
        *returnSize=0;
        return 0;
    }
    int maxSize=(nums1Size>nums2Size)?nums1Size:nums2Size;
    int* res=(int *)malloc(sizeof(int)*maxSize); 
    int index=0;
    for(int i=0;i<nums1Size;i++){
        for(int j=0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                res[index++]=nums1[i];
                continue;
            }
        }
    }
    if(index==0){
        *returnSize=0;
        return 0;
    }
    qsort(res,index,sizeof(res[0]),cmp);
    int tmp=1;
    for(int i=1;i<index;i++){
        if(res[tmp-1]==res[i]){
            continue;
        }else{
            res[tmp++]=res[i];
        }
    }
    *returnSize=tmp;
    return res;
}
