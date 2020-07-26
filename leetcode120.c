
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int f[triangleSize][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        f[i][0] = f[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[i][j] = fmin(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
        }
        f[i][i] = f[i - 1][i - 1] + triangle[i][i];
    }
    int ret = f[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++){
        ret = fmin(ret, f[triangleSize - 1][i]);
    }
	return ret;
}
