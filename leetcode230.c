/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXLEN 100000
#define MAXLEN 100000
int data[MAXLEN] = { 0 };
int arr_num = 0;
void inOrderTree(struct TreeNode* root);
int kthSmallest(struct TreeNode* root, int k) {
	arr_num = 0;
	inOrderTree(root);
	if (arr_num < k) {
	     return 0;
	}
	return data[k - 1];
}
void inOrderTree(struct TreeNode* root) {
	if (root == NULL){
	     return;
        }
	inOrderTree(root->left);
	data[arr_num++] = root->val;
	inOrderTree(root->right);
}
