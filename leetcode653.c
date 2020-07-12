int cmp( const void * a , const void * b ){
    return *( int * )a - *( int * )b;
}
void visitTree( struct TreeNode * root , int * buffer , int * len ){
    *(buffer+*len)=root->val;
    *len+=1;
    if(root->left!=NULL){
        visitTree(root->left,buffer,len);
    }
    if(root->right!=NULL){
        visitTree(root->right,buffer,len);
    }
}
bool findTarget(struct TreeNode* root, int k){
    if(root==NULL&&(root->left==NULL&&root->right==NULL)){
        return false;
    }
    int * buffer=(int *)malloc(sizeof( int ) * 1024 * 128);
    int len=0;
    visitTree(root,buffer,&len);
    qsort(buffer,len,sizeof(int),cmp);
    int left=0;
    int right=len-1;
    while(left<right){
        if(*(buffer+left)+*(buffer+right)>k){
            right--;
        }else if(*(buffer+left)+*(buffer+right)<k){
            left++;
        }else{
            free(buffer);
            return true;
        }
    }
    free(buffer);
    return false;
}
