/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -
/* Should return minimum distance between a and b
   in a tree with given root*/
Node* lca(Node* root , int n1 , int n2 ) {
	// Case 4 -
	if (root == NULL)
		return NULL;

	// Case 1 -
	if (root->data == n1 or root->data == n2)
		return root;

	// Case 2 and 3 -
	Node* left = lca(root->left, n1, n2);
	Node* right = lca(root->right, n1, n2);

	// Case 2 - dono side pe mil gya
	if (left != NULL and right != NULL)
		return root;

	// Case 3 - check either sides
	if (left != NULL)
		return left;
	if (right != NULL)
		return right;
}

// Find the distance
int findNode(Node* root, int val) {
	if (root == NULL)
		return 1e9;

	if (root->data == val)
		return 0;

	int left = findNode(root->left, val);
	int right = findNode(root->right, val);

	return min(left, right) + 1;
}

// LCA nikal lo and waha se distance
int findDist(Node* root, int a, int b) {
	Node* LCA = lca(root, a, b);
	int findA = findNode(LCA, a);
	int findB = findNode(LCA, b);

	return findA + findB;

}