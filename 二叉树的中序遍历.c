int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _inorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	
	_inorderTraversal(root->left, arr, pi);
	arr[(*pi)++] = root->val;
	_inorderTraversal(root->right, arr, pi);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(*returnSize * sizeof(int));
	int i = 0;
	_inorderTraversal(root, arr, &i);

	return arr;
}