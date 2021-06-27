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
	if (root == NULL)	// if there are no elements present
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