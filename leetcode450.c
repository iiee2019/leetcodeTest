struct TreeNode* minNum(struct TreeNode* node){
    if(node->left==NULL){
        return node;
    }
    return minNum(node->left);
}
struct TreeNode* removeMin(struct TreeNode* node){
    if(node->left==NULL){
        struct TreeNode* rightNode=node->right;
        node->right=NULL;
        return rightNode;
    }
    node->left=removeMin(node->left);
    return node;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key<root->val){
        root->left=deleteNode(root->left, key);
        return root;
    }else if(key>root->val){
        root->right=deleteNode(root->right, key);
        return root;
    }else{
        if(root->left==NULL){
            struct TreeNode* rightNode=root->right;
            root->right=NULL;
            return rightNode; 
        }
        if(root->right==NULL){
            struct TreeNode* leftNode=root->left;
            root->left=NULL;
            return leftNode; 
        }
        struct TreeNode* reMin=minNum(root->right);
        reMin->right=removeMin(root->right);
        reMin->left=root->left;

        root->left=root->right=NULL;
        return reMin;
    }
}
