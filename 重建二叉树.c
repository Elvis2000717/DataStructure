#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}TreeNode;

TreeNode* reBuildTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		return NULL;
	}
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = str[*pi];
	(*pi)++;
	root->left = reBuildTree(str, pi);
	(*pi)++;
	root->right = reBuildTree(str, pi);

	return root;
}

void InOrderTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	InOrderTree(root->left);
	printf("%c ", root->val);
	InOrderTree(root->right);
}

int main()
{
	char str[100];
	while (scanf("%s", str) != EOF)
	{
		int i = 0;
		TreeNode* tree = reBuildTree(str, &i);
		InOrderTree(tree);
		printf("\n");
	}

	return 0;
}