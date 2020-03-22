/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int leftlevel(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    return 1+leftlevel(root->left);
}
int rightlevel(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    return 1+rightlevel(root->right);
}

int countNodes(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    int lLevel=leftlevel(root->left);
    int rLevel=rightlevel(root->right);
    if(lLevel==rLevel){
        sum=2*(pow(2,lLevel)-1);
    }else{
        sum+=countNodes(root->right)+countNodes(root->left);
    }
    return sum+1;
}
