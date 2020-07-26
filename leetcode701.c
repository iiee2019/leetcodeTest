struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(root==NULL){
        struct TreeNode* new=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        new->val=val;
        new->left=NULL;
        new->right=NULL;
        return new;
    }
    if(root->val>val){
        root->left=insertIntoBST(root->left,val);
    }else{
        root->right=insertIntoBST(root->right,val);
    }
    return root;
}
