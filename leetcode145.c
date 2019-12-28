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
 #define MAXSIZE 128
typedef struct Stack{
    struct TreeNode* data[MAXSIZE];
    int sp;
}Stack;
void postTraversal(struct TreeNode* root,int* res,int* returnSize);
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize=0;
    int* res=(int*)malloc(MAXSIZE*sizeof(int));
    postTraversal(root,res,returnSize);
    return res;
}
void postTraversal(struct TreeNode* root,int* res,int* returnSize){
    Stack S;
    S.sp=-1;
    struct TreeNode* cur=root;
    struct TreeNode* prev=NULL;
    if(!cur){
        *returnSize=0;
        return NULL;
    }
    while(cur||S.sp!=-1){
        if(cur){
            S.data[++(S.sp)] = cur;
		    cur = cur->left;
        }else{
            cur=S.data[S.sp];
            if(cur->right==NULL||cur->right==prev){
                res[(*returnSize)++]=cur->val;
                S.sp--;
                prev=cur;
                cur=NULL;
            }
            else
            cur=cur->right;
        }
    }
    res[*returnSize] = '\0';
}
