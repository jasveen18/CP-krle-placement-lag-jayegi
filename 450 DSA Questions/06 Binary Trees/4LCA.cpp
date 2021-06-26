/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the least common ancestor of given 2 nodes.

// There are 4 cases to check a LCA.
// 1. If the current node is equal to 'p' or 'q' then that is LCA.
// 2. If 'p' and 'q' lie on both sides of the tree. ek left, ek right.
// 3. If 'p' and 'q' lie on same side of the tree. left or right.
// 4. If 'p' and 'q' is not present on either side of the tree.


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