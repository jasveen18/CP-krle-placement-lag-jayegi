/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a preorder traversal of BST. Construct the tree.

// Approach 1 - Sort the preorder and store it somewhere else.
// Construct the tree from pre order and in order.
// T - O(nLogn) | S - O(n)


// Approach 2 - Logic and properties of BST
// T - O(N) time | O(H) space
TreeNode* bstFromPreorder(vector<int>& preorder) {
	if (preorder.size() == 0)
		return NULL;

	int preIndex = 0;
	return bstFromPreorderHelper(preorder, INT_MIN, INT_MAX, preIndex);
}


TreeNode* bstFromPreorderHelper(vector<int> &preorder, int start, int end, int &preIndex) {
	// No valid node here
	if (preIndex == preorder.size() or preorder[preIndex] < start or preorder[preIndex] > end)
		return NULL;

	// Make the node
	int data = preorder[preIndex++];
	TreeNode* root = new TreeNode(data);
	root->left = bstFromPreorderHelper(preorder, start, data, preIndex);
	root->right = bstFromPreorderHelper(preorder, data, end, preIndex);

	return root;
}