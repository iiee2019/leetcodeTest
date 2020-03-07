/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int TreeSize(struct TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return TreeSize(root->left)+TreeSize(root->right)+1;
}
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    int j=0,k=0,i;
    int size=TreeSize(root)+1;
    struct TreeNode *queue[size],*p;
    int front=0,rear=0;
    int levelnumber;
    int** preColumnSizes=(int**)malloc(sizeof(int*)*size);
    *preColumnSizes=(int*)malloc(sizeof(int)*size);
    int** res1=(int**)malloc(sizeof(int*)*size);
    int** res2=(int**)malloc(sizeof(int*)*size);
    queue[rear]=root;
    rear=(rear+1)%size;
    while(front!=rear){
        levelnumber=(rear-front)%size;
        (*preColumnSizes)[j]=levelnumber;//此处表示输出数组每一层的大小
        res1[j]=(int*)malloc(sizeof(int)*levelnumber);
        for(i=0;i<levelnumber;i++){
            p=queue[front];
            res1[j][i]=p->val;
            front=(front+1)%size;
            if(p->left!=NULL){
                queue[rear]=p->left;
                rear=(rear+1)%size;
            }
            if(p->right!=NULL){
                queue[rear]=p->right;
                rear=(rear+1)%size;
            }
        }
        j++;
    }
    *returnSize=j;

    *returnColumnSizes=(int*)malloc(sizeof(int)*size);
    for(i=0,k=(j-1);i<j;i++,k--){
        (*returnColumnSizes)[i]=(*preColumnSizes)[k];
        res2[i]=res1[k];
    }
    return res2;
}
