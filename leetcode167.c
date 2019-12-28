/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* res = (int *)malloc(2 * sizeof(int));
	int* left = numbers;
	int* right = numbers + (numbersSize - 1);
	while ((*left + *right)!=target)
	{
		if ((*left + *right)<target)
		{
			*left++;
		}
		else
			*right--;
	}
	res[0] = left-numbers+1;
	res[1] = right-numbers+1;
 	*returnSize=2;
	return res;
}
