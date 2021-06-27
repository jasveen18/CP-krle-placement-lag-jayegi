/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Replace every element with the least greater element on its right
// Input: [8, 58, 71, 18, 31, 32, 63, 92,
//          43, 3, 91, 93, 25, 80, 28]
// Output: [18, 63, 80, 25, 32, 43, 80, 93,
//          80, 25, 93, -1, 28, -1, -1]


// Approach 1 - Brute Force
// O(N*N) pe using two loops.

// Approach 2 - Using BST. Pro tip - Think of BST to solve problems now. When you consider the list of algos and DS to solve.
// Idea is to traverse right to left.
// Then keep inserting the element.
// While inserting take the successor of the element.

// If there is no successor that means wo sbse bada hai, then put -1.

// Two function -
// 1. Insert Function
// 2. Replace Function

void replaceWithLeastGreater(int arr[], int n) {
	Node* root = NULL;

	// Start from end to start.
	for (int i = n - 1; i >= 0; i--) {
		Node* successor = NULL;

		// Insert into BST and also update successor
		root = insertIntoBST(root, arr[i], successor);

		if (successor)
			arr[i] = successor->data;
		else
			arr[i] = -1;	// No larger element found
	}

	return;
}


Node* insertIntoBST(Node* root, int value, Node* &successor) {
	if (root == NULL) {
		return new Node(value);
	}

	if (root->data > value) {
		successor = root;
		root->left = insertIntoBST(root->left, value, successor);
	} else if (root->data < value) {	// Don't update successor here, coz ye pred hai
		root->right = insertIntoBST(root->right, value, successor);
	}

	return root;
}