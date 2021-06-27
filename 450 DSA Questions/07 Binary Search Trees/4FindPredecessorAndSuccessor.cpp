/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find pred and succ of a given node in Binary search tree


// Inorder Traversal - O(N) time | O(H) space (recursive stack)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	if (root == NULL)
		return root;

	findPreSuc(root->left, pre, suc, key);

	if (root->data < key) // Keep updating as sorted manner pe traversal hai
		pre = root;

	if (suc = NULL and root->data > key) // As soon as found once, don't update
		suc = root;

	findPreSuc(root->right, pre, suc, key);
}


// Optimized version - O(H) time | O(1) space
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	Node* p = NULL, *s = NULL;

	// Traverse in BST as you would to find the node, and traverse till we find the node.
	while (root and root->key != key) {
		if (root->key < key) {
			p = root;
			root = root->right;
		} else {	// Observation: successor parent ke pass hi hoga
			s = root;
			root = root->left;
		}
	}

	// If node not present toh range hi return kr do.
	if (root == NULL) {
		pre = p;
		suc = s;
		return;
	}

	// If node present hai toh p or s mein se koi ek node ban gya hai, uska pehle ya baad wala dhundh re ab.

	// Ye krre hai kyunki now I want to find the least node of the parent (s pe parent stored hai)
	// Right side se smallest node chaiye.
	if (root->right == NULL) {
		suc = s;
	} else {
		Node* curr = root->right;

		while (curr->left)
			curr = curr->left;

		suc = curr;
	}

	// ye krre hai kyunki ab left side se largest node chaiye
	if (root->left == NULL) {
		pre = p;
	} else {
		Node* curr = root->left;

		while (curr->right)
			curr = curr->right;

		pre = curr;
	}

	return;
}