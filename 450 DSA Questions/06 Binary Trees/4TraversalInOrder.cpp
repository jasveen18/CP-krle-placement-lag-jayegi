/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the InOrder Traversal of a Tree (Recursive and Iterative)

// Recursive Solution
void inOrderRecursive(TreeNode* root) {
	if (root == NULL)
		return root;

	inOrderRecursive(root->left);
	cout << root->val << " "; // Do the operation
	inOrderRecursive(root->right);
}


// Iterative Operation
vector<int> inOrderIterative(TreeNode* root) {
	if (root == NULL)
		return {};

	// Stack to simulate the recursive function
	// Store the node and it's state
	// 1 -> visited once, print when preorder
	// 2 -> visited twice, print when inorder
	// 3 -> visited thrice, print when postorder
	stack<pair<TreeNode*, int>> st;
	vector<int> inOrderRes;

	st.push({root, 1});

	while (!st.empty()) {
		TreeNode* curr = st.top().first;
		int stateCurr = st.top().second;
		st.pop();

		// If seen for the first time
		if (stateCurr == 1) {
			stateCurr++;
			st.push({curr, stateCurr});

			// preOrderRes.push_back(curr->val);  // Since we don't want pre order here

			// Push only left here
			if (curr->left)
				st.push({curr->left, 1});
		} else if (stateCurr == 2) {
			stateCurr++;
			st.push({curr, stateCurr});

			inOrderRes.push_back(curr->val);

			// Push only right here
			if (curr->right)
				st.push({curr->right, 1});
		} else {
			// postOrderRes.push_back(curr->val); // Since we don't want post order here
		}
	}

	return inOrderRes;
}