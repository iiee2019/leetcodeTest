void helper(struct TreeNode* father,struct TreeNode* node){
    if(node==NULL){
        return ;
    }
    helper(node,node->left);
    helper(node,node->right);
    if(node->val==0){
        if(father==NULL) return ;
        if(father->left==node&&node->left==NULL&&node->right==NULL){
            father->left=NULL;
        }else if(father->right==node&&node->left==NULL&&node->right==NULL){
            father->right=NULL;
        }
    }
}
struct TreeNode* pruneTree(struct TreeNode* root){
    helper(NULL,root);
    if(root->val==0&&root->left==NULL&&root->right==NULL){
        return NULL;
    }
    return root;
}
