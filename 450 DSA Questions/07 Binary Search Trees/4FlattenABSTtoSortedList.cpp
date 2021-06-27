/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Flatten a BST to Sorted Linked List

Node* flattenBSTtoLL(Node* root) {
	Node* head = NULL;
	Node* tail = NULL;

	flattenBSTtoLLHelper(root, head, tail);
}


Node* flattenBSTtoLLHelper(Node* root, Node* &head, Node* &tail) {
	// In order traversal
	if (root == NULL)
		return NULL;

	flattenBSTtoLLHelper(root->left, head, tail);

	// Operations
	if (head == NULL) { // if we have not got our head yet.
		head = root;
		tail = root;
	} else {	// head mil gya hai, tail ko update krke badhao ab.
		tail->right = root;
		tail->left = NULL; // Remove bindings for left pointer
		tail = tail->right;
	}

	flattenBSTtoLLHelper(root->right, head, tail);
}

