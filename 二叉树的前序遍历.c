int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _preorderTraversal(struct TreeNode* root, int* arr, int* pi)
{
	if (root == NULL)
	{
		return;
	}
	arr[(*pi)++] = root->val;
	_preorderTraversal(root->left, arr, pi);
	_preorderTraversal(root->right, arr, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	*returnSize = TreeSize(root);
	int* arr = (int*)malloc(*returnSize * sizeof(int));
	int i = 0;
	_preorderTraversal(root, arr, &i);

	return arr;
}