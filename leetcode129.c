/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int sum,int* res){
    if(root==NULL){
        return ;
    }
    sum=sum*10+root->val;
    if(root->left==NULL&&root->right==NULL){
        *res+=sum;
    }
    dfs(root->left,sum,res);
    dfs(root->right,sum,res);
}

int sumNumbers(struct TreeNode* root){
    int sum=0;
    int res=0;
    int* ptr=(int*)malloc(sizeof(int));
    ptr=&res;
    dfs(root,sum,ptr);
    return res;
}
