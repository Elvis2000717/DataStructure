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

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}