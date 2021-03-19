int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _postorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return;
	}

	_postorderTraversal(root->left, arr, pi);
	_postorderTraversal(root->right, arr, pi);
	arr[(*pi)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(*returnSize * sizeof(int));

	int i = 0;
	_postorderTraversal(root, arr, &i);

	return arr;
}