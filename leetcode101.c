/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmLN(struct TreeNode*leftLN,struct TreeNode*rightLN);
bool isSymmetric(struct TreeNode* root){
    if(root==NULL)
        return true;
    return isSymmLN(root->left,root->right);
}
bool isSymmLN(struct TreeNode*leftLN,struct TreeNode*rightLN){
    if(leftLN==NULL&&rightLN==NULL)
        return true;
    if(leftLN==NULL)
        return false;
    if(rightLN==NULL)
        return false;
    if(leftLN->val!=rightLN->val)
        return false;
    return isSymmLN(leftLN->left,rightLN->right)&&isSymmLN(leftLN->right,rightLN->left);
}
