int MAX(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}
int rob(int* nums, int numsSize) {
	if (numsSize == 0||nums==NULL)
		return 0;
	if (numsSize == 1)
		return nums[0];
	int* dp1 = (int *)malloc(numsSize * sizeof(int)); //偷第一间
	int* dp0 = (int *)malloc(numsSize * sizeof(int)); //不偷第一间
	dp1[0] = nums[0];
    dp1[1] = nums[0];
	dp0[0] = 0;
	dp0[1] = nums[1];
	for (int i = 2; i <numsSize; i++) {
		dp1[i] = MAX(dp1[i - 1],dp1[i - 2] + nums[i]);
		dp0[i] = MAX(dp0[i - 1],dp0[i - 2] + nums[i]);
	}
	return MAX(dp0[numsSize-1] , dp1[numsSize - 2]);

}
