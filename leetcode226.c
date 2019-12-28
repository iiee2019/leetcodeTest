/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL)
        return root;
    struct TreeNode* leftNode=root->left;
    root->left=invertTree(root->right);
    root->right=invertTree(leftNode);
    return root;
}
