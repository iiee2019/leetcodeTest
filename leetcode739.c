/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize=TSize;
    int *result=(int *)malloc(TSize*sizeof(int));
    if(result==NULL){
        return NULL;
    }
    memset(result, 0, sizeof(int) * TSize);
    for (int i = TSize - 2; i >= 0; i--) {
        for (int j = i + 1; j < TSize; j += result[j]) {
            if (T[j] > T[i]) {
                result[i] = j - i;
                break;
            }else if (result[j] == 0) {
                result[i] = 0;
                break;
            }
        }
    }
    return result;
}
