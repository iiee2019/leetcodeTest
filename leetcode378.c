int cmp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k){
    int* nums=(int*)malloc(sizeof(int)*matrixSize*matrixSize);
    int index=0;
    int i,j;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixSize;j++){
            nums[index++]=matrix[i][j];
        }
    }
    qsort(nums,index,sizeof(int),cmp);
    return nums[k-1];
}
