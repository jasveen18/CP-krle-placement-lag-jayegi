/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Create the mirror of the tree.
// Create new nodes but for node->left, give mirror->right
void mirrorTree(Node* root, Node** mirror) {
	// Base Case -
	if (root == NULL	) {
		mirror = NULL;
		return;
	}

	// Recursive Case
	*mirror = new Node(root->val);
	// Pass the left with right and vice versa. Take care of your pointers.
	mirrorTree(root->left, &((*mirror) -> right));
	mirrorTree(root->right, &((*mirror) -> left));

	return;
}


// Change the bindings of the original tree only
Node* mirrorTree(Node* root) {
	// Base Case -
	if (root == NULL)
		return root;

	// Swap the left and right nodes.
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;

	if (root->left)
		mirrorTree(root->left);
	if (root->right)
		mirrorTree(root->right);

	return root;
}