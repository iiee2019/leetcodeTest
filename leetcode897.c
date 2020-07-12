struct TreeNode * rebuildTree( struct TreeNode * root , struct TreeNode * curr , struct TreeNode * form ){
    if(root->left!=NULL){
        curr=rebuildTree(root->left , curr ,form);
    }
    curr->val=root->val;
    curr->right=( struct TreeNode * )malloc( sizeof( struct TreeNode )*1);
    form->right=curr;
    curr=curr->right;
    curr->left=curr->right=NULL;

    if(root->right!=NULL){
        curr=rebuildTree(root->right , curr ,form);
    }
    return curr;
}
struct TreeNode* increasingBST(struct TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    struct TreeNode* res=(struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    struct TreeNode* curr=res;
    struct TreeNode* form=(struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    curr->left=curr->right=NULL;
    curr=rebuildTree(root , curr ,form);
    form->right->right=NULL;
    free(form);
    return res;
}
