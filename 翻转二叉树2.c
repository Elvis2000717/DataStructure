struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL)
	{
		return NULL;
	}

	struct TreeNode* right = root->right;
	root->right = invertTree(root->left);
	root->left = invertTree(right);

	return root;
}