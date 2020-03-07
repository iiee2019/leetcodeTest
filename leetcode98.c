/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isLeft(struct TreeNode* node,int rootVal){
    while(node->right!=NULL){
        node=node->right;
    }
    return rootVal>node->val;
}
bool isRight(struct TreeNode* node,int rootVal){
    while(node->left!=NULL){
        node=node->left;
    }
    return rootVal<node->val;
}
bool isValidBST(struct TreeNode* root){
    if(root==NULL){
        return true;
    }
    int left = 0, right = 0;
    bool lres = true,rres = true;
    if(root->right){
        right = 1;
        if(root->right->val <= root->val){ 
            return false;
        }
        rres = isValidBST(root->right);
        if(rres){
            rres = isRight(root->right,root->val);
        } else{
            return false;
        }
    }
    if(root->left){
        left = 1;
        if(root->left->val >= root->val){ 
            return false;}
        lres = isValidBST(root->left);
        if(lres){
            lres = isLeft(root->left,root->val);
        } else{
            return false;
        }
    }
    return rres&&lres;
}
