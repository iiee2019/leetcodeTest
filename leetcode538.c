void SubTreeSum(struct TreeNode* node,int* outSum){
    if(node==NULL){
        return ;
    }
    *outSum = *outSum + node->val;
    SubTreeSum(node->left,outSum);
    SubTreeSum(node->right,outSum);
}
void SubTreeRenew(struct TreeNode* node,int* outSum){
    int tmpVal;
    if(node==NULL){
        return ;
    }
    SubTreeRenew(node->left,outSum);
    tmpVal=node->val;
    node->val+=*outSum-tmpVal;
    *outSum=*outSum-tmpVal;
    SubTreeRenew(node->right,outSum);
}
struct TreeNode* convertBST(struct TreeNode* root){
    int outSum=0;
    if(root==NULL){
        return root;
    }
    SubTreeSum(root,&outSum);
    SubTreeRenew(root,&outSum);
    return root;
}
