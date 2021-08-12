/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1.965. Univalued Binary Tree
bool isUnivalTree(TreeNode* root, TreeNode* parent = NULL) {
	if (root == NULL)
		return true;

	if (parent and root->val != parent->val)
		return false;

	bool left = isUnivalTree(root->left, root);
	bool right = isUnivalTree(root->right, root);

	return left and right;
}