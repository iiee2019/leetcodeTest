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
 int cmp(const int* a,const int* b){
     return *(int*)a-*(int*)b;
 }
 void preOrder(struct TreeNode* root,int* data,int* returnSize){
    if(root==NULL){
        return ;
    }
    data[(*returnSize)++]=root->val;
    preOrder(root->left,data,returnSize);
    preOrder(root->right,data,returnSize);
 }
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    *returnSize=0;
    if(root1==NULL&&root2==NULL){
        return NULL;
    }
    int * ret=(int*)malloc(sizeof(int)*10000);
    preOrder(root1,ret,returnSize);
    preOrder(root2,ret,returnSize);
    qsort(ret,*returnSize,sizeof(int),cmp);
    return ret;
}
