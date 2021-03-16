struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL || (root->left == NULL && root->right == NULL))
	{
		return root;
	}

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = rmp;

	invertTree(root->left);
	invertTree(root->right);

	return root;
}