/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isLeaf(struct TreeNode* treeLN);
int sumOfLeftLeaves(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    if(isLeaf(root->left)){
        return root->left->val+sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}
bool isLeaf(struct TreeNode* treeLN){
    if(treeLN==NULL){
        return false;
    }
    return treeLN->left==NULL&&treeLN->right==NULL;
}
