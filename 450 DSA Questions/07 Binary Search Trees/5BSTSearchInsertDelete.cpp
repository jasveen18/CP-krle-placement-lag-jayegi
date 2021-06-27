class BST {
	int data;
	BST *left, *right;

public:
	// Default Constructor
	BST();

	// Parameterized Constructor
	BST(int);

	// Insert function
	BST* insertNode(BST*, int);

	// Inorder Traversal
	void inOrderTraversal(BST*);

	// Search a key - modification, we can also pass a node
	BST* searchNode(BST*, int);

	// Delete a node - modificatin, we can also pass a node
	BST* deleteNode(BST*, int);

	// Return the minimum value of BST
	int minElementBST(BST*);

	// Return the maximum value of BST
	int maxElementBST(BST*);
};


// Default Constructor
BST::BST(): data(0), left(NULL), right(NULL) {}

// Parameterized Constructor
BST::BST(int value) {
	data = value;
	left = NULL; right = NULL;
}

// Insert Function
BST* BST::insertNode(BST* root, int value) {
	if (root == NULL)	// if there are no elements(reached correct location) present insert node
		return new BST(value);

	// Find the correct position to insert BST
	if (value > root->data)	// If it belongs in the right part of the tree.
		root->right = insertNode(root->right, value);
	else   					// If it belongs in the left part of the tree.
		root->left = insertNode(root->left, value);

	return root;
}


// In-Order Traversal of BST (gives a sorted list)
void BST::inOrderTraversal(BST* root) {
	// Base Case -
	if (root == NULL)
		return;

	// Recursive Case -
	inOrderTraversal(root->left);
	cout << root->data << " "; // Do the operation
	inOrderTraversal(root->right);
}


// Search if the element is present or not, if present, return node or null if not present.
BST* BST::searchNode(BST* root, int key) {
	if (root == NULL or root->data == key)
		return root;

	if (key < root->data) 	// key is smaller toh left part pe jao
		return searchNode(root->left, key);
	else   					// key is greater toh right part pe jao
		return searchNode(root->right, key);

	return NULL;
}


// Delete the node if found and then return the new updated root.
BST* BST::deleteNode(BST* root, int key) {
	// Base Case -
	if (root == NULL)
		return root;

	// Find the node to be deleted
	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	else { // If we find the correct node, we have 4 cases now.

		// Case 1 - node doesn't have any children. Delete the node and return null.
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// Case 2 - node only have left children, means delete the node and return the left children
		if (root->right == NULL)
			return root->left;

		// Case 3 - node only have right children
		if (root->left == NULL)
			return root->right;

		// Case 4 - node has both children, we will have to handle this case
		// Idea is to find the smallest value node from right children, and usko root->left ka kaar bhaar de denge
		// This will maintain our order.

		BST* rightSmallest = root->right;

		// Traverse till the smallest possible node
		while (rightSmallest->left != NULL) {
			rightSmallest = rightSmallest->left;
		}

		// Root ka saara left children isse de do
		rightSmallest->left = root->left;

		// This will the new thing in place of root.
		return root->right;
	}

	return root;
}


// Min value
int BST::minElementBST(BST* root) {
	if (root == NULL)
		return INT_MAX;

	while (root->left)
		root = root->left;

	return root->data;
}


// Max Value
int BST::maxElementBST(BST* root) {
	if (root == NULL)
		return INT_MIN;

	while (root->right)
		root = root->right;

	return root->data;
}