/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the top view of the tree
vector<int> topView(Node *root) {
	if (root == NULL)
		return {};

	// Map to store height of each node
	map<int, int> nodeHeight;
	queue<pair<Node*, int>> q;

	q.push({root, 0});
	nodeHeight[0] = root->data;

	while (!q.empty()) {
		Node* curr = q.front().first;
		int currHeight = q.front().second;
		q.pop();

		if (nodeHeight.find(currHeight) == nodeHeight.end()) {
			nodeHeight[currHeight] = curr->data;
		}

		if (curr->left) q.push({curr->left, currHeight - 1});
		if (curr->right) q.push({curr->right, currHeight + 1});
	}

	vector<int> res;
	for (auto num : nodeHeight)
		res.push_back(num.second);

	return res;
}