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
 void preTraversal(struct TreeNode* root,  int* res,int* returnSize);
typedef struct Stack{
    struct TreeNode* stack[STACKSIZE];
    int sp;
}Stack; 
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    int * res=malloc(STACKSIZE*sizeof(int));
    preTraversal(root,res,returnSize);
    return res;
}
void preTraversal(struct TreeNode* root,  int* res,int* returnSize){
    struct TreeNode* cur=root;
    Stack S;
    S.sp=-1;
    while(cur||S.sp!=-1){
        while(cur){
            res[(*returnSize)++]=cur->val;
            S.stack[++(S.sp)]=cur;
            cur=cur->left;
        }
        if(S.sp!=-1){
            cur=S.stack[(S.sp)--];
            cur=cur->right;
        }
    }
    res[*returnSize]='\0';
}
