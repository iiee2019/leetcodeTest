/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int Max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int MaxDepth(struct TreeNode* treeLN);
bool isBalanced(struct TreeNode* root){
    if(root==NULL) return true;
    int lnum=MaxDepth(root->left);
    int rnum=MaxDepth(root->right);
    return (abs(lnum-rnum)<=1)&&isBalanced(root->left)&&isBalanced(root->right);

}
int MaxDepth(struct TreeNode* treeLN){
    if(treeLN==NULL)
        return 0;
    return Max(MaxDepth(treeLN->left),MaxDepth(treeLN->right))+1;
}
