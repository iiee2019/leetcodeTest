#define MIN(a,b) ((a) < (b) ? (a) : (b)) 
void inorder(struct TreeNode* root, int *pre, int *min) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, pre, min);
    if ((*pre) != -1) {
        *min = MIN(*min, root->val - (*pre));
    }
    (*pre) = root->val;
    inorder(root->right, pre, min);
    return;
}

int getMinimumDifference(struct TreeNode* root){
    int min = INT_MAX;
    int pre = -1;
    inorder(root, &pre, &min);
    return min;
}
