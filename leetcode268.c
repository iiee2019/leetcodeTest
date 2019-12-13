int missingNumber(int* nums, int numsSize){
    int m = numsSize;
	int n = 2 * m + 1;
	int* arr = (int *)malloc(n*sizeof(int));
	int res = 0;
	for (int i=0;i<m;i++) {
		arr[i] = nums[i];
	}
	for (int i = m;i<n;i++) {
		arr[i] = i-m;
	}
	for (int i = 0; i < n; i++) {
		res = res^arr[i];
	}
	return res;
}
