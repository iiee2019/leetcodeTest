/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize<=0){
        return NULL;
    }
    struct TreeNode* res=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    res->val=postorder[postorderSize-1];
    int index=0;
    while(inorder[index]!=postorder[postorderSize-1]&&index<inorderSize){
        index++;
    }
    res->left=buildTree(inorder, index, postorder, index);
    res->right=buildTree(inorder+index+1, inorderSize-index-1, postorder+index, postorderSize-1-index);
    return res;
}
