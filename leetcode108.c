/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
struct TreeNode* sortedSubArrayToBST(int* nums, int start,int end){
    int l=start;
    int r=end-1;
    int mid=l+(r-l)/2;
    //struct TreeNode* ret=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val=nums[numsSize];
    ret->left=sortedSubArrayToBST(nums,0,mid-1);
    ret->right=sortedArrayToBST(nums,mid+1,numsSize-1);
    return ret;
}
*/
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize<=0){
        return NULL;
    }
    struct TreeNode* ret=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int l=0;
    int r=numsSize-1;
    int mid=l+(r-l)/2;
    ret->val=nums[mid];
    ret->left=sortedArrayToBST(nums,mid);
    ret->right=sortedArrayToBST(nums+mid+1,numsSize-1-mid);
    return ret;
}
