/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int size=digitsSize+1;
    int* res=( int*)malloc(sizeof(int)*size); 
    for(int i=digitsSize-1;i>=0;i--){
        if(digits[i]<9){
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    res[0]=1;
    for(int i=1;i<size;i++){
        res[i]=0;
    }
    *returnSize=size;
    return res;
}
