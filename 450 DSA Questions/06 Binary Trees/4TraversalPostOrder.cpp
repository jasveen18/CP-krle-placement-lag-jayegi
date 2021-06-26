/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the post order traversal of tree (recursive and iterative)

// Recursive Solution
void postOrderRecursive(TreeNode* root) {
	if (root == NULL)
		return root;

	postOrderRecursive(root->left);
	postOrderRecursive(root->right);
	cout << root->val; // Do the operation
}


// Iterative Solution - Please see inorder for explanation
vector<int> postOrderIterative(TreeNode* root) {
	if (root == NULL)
		return {};

	vector<int> postOrderRes;
	stack<pair<TreeNode*, int>> st;

	st.push({root, 1});

	while (!st.empty()) {
		TreeNode* curr = st.top().first;
		int stateCurr = st.top().second;
		st.pop();

		if (stateCurr == 1) {
			stateCurr++;
			st.push({curr, stateCurr});

			if (curr->left)
				st.push({curr->left, 1});
		} else if (stateCurr == 2) {
			stateCurr++;
			st.push({curr, stateCurr});

			if (curr->right)
				st.push({curr->right, 1});
		} else {
			postOrderRes.push_back(curr->val);
		}
	}

	return postOrderRes;
}