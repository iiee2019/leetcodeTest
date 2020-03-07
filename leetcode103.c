/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#define SWAP(a, b) {int tmp = a; a = b; b = tmp;}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int l = 0, r = 0;
    struct TreeNode* Q[10000] = {NULL};
    if (root != NULL) {
        Q[r++] = root;
    }
    int **res = malloc(sizeof(int *) * 10000);
    * returnSize = 0;
    * returnColumnSizes = malloc(sizeof(int) * 10000);
    while (r > l) {
        int count = r - l;
        res[* returnSize] = malloc(sizeof(int) * count);
        returnColumnSizes[0][* returnSize] = count;
        int tmp = l;
        for (int i = 0; i < count; i++) {
            res[* returnSize][i] = Q[tmp + i]->val;
            if (Q[tmp + i]->left) {
                Q[r++] = Q[tmp + i]->left;
            }
            if (Q[tmp + i]->right) {
                Q[r++] = Q[tmp + i]->right;
            }
            l++;
        }
        if ((* returnSize) % 2 == 1) {
            for (int i = 0; i < count / 2; i++) {
                SWAP(res[* returnSize][i], res[* returnSize][count - i - 1])
            }
        }
        (* returnSize)++;
    }
    return res;
}

