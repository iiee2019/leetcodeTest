/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSubtreeFromRoot(struct TreeNode* s, struct TreeNode* t);
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s==NULL){
        return false;
    }
    return isSubtreeFromRoot(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);
}
bool isSubtreeFromRoot(struct TreeNode* s, struct TreeNode* t){
    if(s==NULL&&t==NULL){
        return true;
    }
    if(s==NULL||t==NULL){
        return false;
    }
    if(s->val!=t->val){
        return false;
    }
    return isSubtreeFromRoot(s->left,t->left)&&isSubtreeFromRoot(s->right,t->right);
}
