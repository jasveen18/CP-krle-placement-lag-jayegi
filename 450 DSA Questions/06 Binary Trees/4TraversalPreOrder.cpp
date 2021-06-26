/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the pre order traversal of the tree (recursive and iterative)

// Recursive Solution
void preOrderRecursive(TreeNode *root) {
	if (root == NULL)
		return root;

	cout << root->val; // Do the operation
	preOrderRecursive(root->left);
	preOrderRecursive(root->right);
}


// Iterative Solution
vector<int> preOrderIterative(TreeNode* root) {
	if (root == NULL)
		return {};

	// Same as the inorder, we will maintain states, refer that first for concept
	vector<int> preOrderRes;
	stack < pair<TreeNode*, int>> st;

	st.push({root, 1});

	while (!st.empty()) {
		TreeNode* curr = st.top().first;
		int stateCurr = st.top().second;
		st.pop();

		if (stateCurr == 1) {
			stateCurr++;
			st.push({curr, stateCurr});

			preOrderRes.push_back(curr->val);

			if (curr->left)
				st.push({curr->left, 1});
		} else if (stateCurr == 2) {
			stateCurr++;
			st.push({curr, stateCurr});

			// inOrderRes.push_back(curr->val);

			if (curr->right)
				st.push({curr->right, 1});
		} else {
			// postOrderRes.push_back(curr->val);
		}
	}

	return preOrderRes;
}