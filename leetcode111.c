/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int MIN(int a,int b){
    if(a>b)
        return b;
    else
        return a;
}
int minDepth(struct TreeNode* root){
    if(root==NULL)
        return NULL;
    int leftVal=minDepth(root->left);
    int rightVal=minDepth(root->right);
    if(rightVal==0||leftVal==0)
        return (leftVal+rightVal+1);
    return MIN(leftVal,rightVal)+1;
}
