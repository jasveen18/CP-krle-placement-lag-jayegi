/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert a BST to balanced BST.

// Approach -
// Store the nodes of BST through inorder traversal.
// Now start creating a new tree with mid value as root and then (start, mid-1) as left subtree and (mid+1, end) as right subtree.

Node* convertBSTtoBalancedBST(Node* root) {
	vector<Node*> data;
	storeNodesInorder(root, data);

	root = buildBalancedTree(data, 0, data.size() - 1);
	return root;
}

void storeNodesInorder(Node* root, vector<Node*> &data) {
	if (root == NULL)
		return root;

	storeNodesInorder(root->left, data);
	data.push_back(root);
	storeNodesInorder(root->right, data);
}

Node* buildBalancedTree(vector<Node*> &nodes, int start, int end) {
	// Base Case -
	if (start > end)
		return NULL;

	int mid = (start + end) / 2;
	Node* root = nodes[mid];

	root->left = buildBalancedTree(nodes, start, mid - 1);
	root->right = buildBalancedTree(nodes, mid + 1, end);

	return root;
}