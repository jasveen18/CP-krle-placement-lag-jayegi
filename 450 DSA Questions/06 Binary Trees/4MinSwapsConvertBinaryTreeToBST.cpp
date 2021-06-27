/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min number of swaps to convert a binary tree to binary search tree.
// The data in the nodes are numbered from 1 to N.

// We will use the property of BST that it is a sorted array when the inorder traversal is taken.

// Therefore, just take the inorder traversal of the binary tree and find min swap required to sort it.


int minSwapsRequiredTreeToBST(Node* root) {
	vector<int> data;
	inOrderStore(root, data);

	// Now we need to find the min swaps required to sort this array.
	// We will use the graph method to find this.
	return minSwapsRequiredToSort(data);
}

void inOrderStore(Node* root, vector<int> &data) {
	if (root == NULL)
		return;

	inOrderStore(root->left);
	data.push_back(root->data);
	inOrderStore(root->right);
}


int minSwapsRequiredToSort(vector<int> &nums) {
	int n = nums.size();
	int swaps = 0;

	vector<pair<int, int>> graph(n);
	for (int i = 0; i < n; i++) {
		graph[i].first = nums[i];
		graph[i].second = i;
	}

	sort(graph.begin(), graph.end());

	// Find the incorrect indexes
	for (int i = 0; i < n; i++) {
		if (i == graph[i].second)
			continue;

		// Swap the incorrect elements
		swap(graph[i].first, graph[graph[i].second].first);
		swap(graph[i].second, graph[graph[i].second].second);

		if (i != graph[i].second)
			i--;
		swaps++;
	}

	return swaps;
}