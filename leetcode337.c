/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Max(int a,int b){
    if(a>b){
        return a;
    }
    else{
         return b;
    }
}
int rob(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int val1=root->val;
    if(root->left!=NULL){
        val1+=rob(root->left->left)+rob(root->left->right);
    }
    if(root->right!=NULL){
        val1+=rob(root->right->left)+rob(root->right->right);
    }
    int val2=rob(root->left)+rob(root->right);
    return Max(val1,val2);
}
