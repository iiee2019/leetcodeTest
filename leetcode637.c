#define MAXSIZE 1024 
#define MAX(a,b) ((a) > (b) ? (a) : (b))
void dfs(struct TreeNode* root, double *res, int *cnt, int idx, int *returnSize) {
    if (root == NULL) {
        return;
    }
    res[idx] += (double)root->val;
    cnt[idx]++;
    (*returnSize) = MAX(*returnSize, idx + 1);
    dfs(root->left, res, cnt, idx + 1, returnSize);
    dfs(root->right, res, cnt, idx + 1, returnSize);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    double *res = (double*)malloc(sizeof(double) * MAXSIZE);
    int *cnt = (int*)malloc(sizeof(int) * MAXSIZE);
    int i;
    for (i = 0; i < MAXSIZE; i++) {
        res[i] = 0.0;
        cnt[i] = 0;
    }
    *returnSize = 0;
    dfs(root, res, cnt, 0, returnSize);
    for (i = 0; i < (*returnSize); i++) {
        res[i] /= cnt[i];
    }
    free(cnt);
    return res;
}
