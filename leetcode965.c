/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool dfs(struct TreeNode* root,int val){
    if(root==NULL){
        return true;
    }
    int rootVal=root->val;
    if(rootVal!=val){
        return false;
    }
    return dfs(root->left,val)&&dfs(root->right,val);
}
bool isUnivalTree(struct TreeNode* root){
    if(root==NULL){
        return true;
    }
    int val=root->val;
    bool res=dfs(root,val);
    return res;
}
