/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the boundary traversal of a tree
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// The idea is to print the left side top down without left node,
// then print the leaf nodes.
// then print the right side from bottom up without leaf node.

void getNonLeafNodesLeft(Node* root, vector<int> &nums) {
	while (root != NULL) {
		// Check for non-leaf node
		if (root->left or root->right)
			nums.push_back(root->data);

		if (root->left)
			root = root->left;
		else
			root = root->right;
	}

	return;
}


void getLeafNodesInorder(Node* root, vector<int> &nums) {
	if (root == NULL)
		return;

	getLeafNodesInorder(root->left, nums);

	// Check for leaf node
	if (root->left == NULL and root->right == NULL)
		nums.push_back(root->data);

	getLeafNodesInorder(root->right, nums);
}


void getNonLeafNodesRight(Node* root, vector<int> &nums) {
	vector<int> temp;
	while (root) {
		// Check for non-leaf
		if (root->left or root->right)
			temp.push_back(root->data);

		if (root->right)
			root = root->right;
		else
			root = root->left;
	}

	// Reverse kyunki bottom up krni hai
	reverse(temp.begin(), temp.end());
	for (int i = 0; i < temp.size(); i++)
		nums.push_back(temp[i]);

	return;
}


vector<int> boundaryTraversal(Node* root) {
	if (root == NULL)
		return {};

	vector<int> res;
	res.push_back(root->data);

	getNonLeafNodesLeft(root->left, res);
	getLeafNodesInorder(root, res);
	getNonLeafNodesRight(root->right, res);

	return res;
}