/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define STACKSIZE 128
 typedef struct Stack{
      struct TreeNode *data[STACKSIZE];
      int sp;
 }Stack;
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    int* res=(int*)malloc(sizeof(int)*STACKSIZE);
    inTraversal(root, res,returnSize);
    return res;
}
void inTraversal(struct TreeNode* root, int* res,int* returnSize){
    Stack S;
    S.sp=-1;
    if(!root){
        *returnSize=0;
        return 0;
    }
   struct TreeNode* cur=root;
    while(cur||S.sp!=-1){
        while(cur){ 
            S.data[++(S.sp)]=cur;
            cur=cur->left;
        }
        if(S.sp!=-1){
            cur=S.data[(S.sp)--];
            res[(*returnSize)++]=cur->val;
            cur=cur->right;
        }
    }
    res[*returnSize] = '\0';
}
