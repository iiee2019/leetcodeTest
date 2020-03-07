/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL)){
        return ;
    }
    flatten(root->left);
    flatten(root->right);
    while(root->left){
        struct TreeNode* p=root->left;
        while(p->right){
            p=p->right;
        }
        p->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }
}
