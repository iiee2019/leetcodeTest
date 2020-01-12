/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int pathStartFromRoot(struct TreeNode* root, int sum);
int pathSum(struct TreeNode* root, int sum){
    if(root==NULL){
        return 0;
    }
    int res=pathStartFromRoot(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    return res;
}
int pathStartFromRoot(struct TreeNode* root, int sum){
    if(root==NULL){
        return 0;
    }
    int ret=0;
    if(sum==root->val){
        ret++;
    }
    ret+=pathStartFromRoot(root->left, sum-root->val)+pathStartFromRoot(root->right, sum-root->val);
    return ret;
}
