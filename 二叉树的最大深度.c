int max(int x, int y)
{
	return x > y ? x : y;
}

int maxDepth(struct TreeNode* root){
	if (root == NULL)
	{
		return 0;
	}

	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}