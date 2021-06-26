/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the diagonal view of the tree

// The idea is to decrease the height when going left, but remain same when going right, as wo slope bana dega phir.
vector<int> diagonalTraversal(Node *root) {
	if (root == NULL)
		return {};

	// Map to store height of each node
	map<int, vector<int>> nodeHeight;
	queue<pair<Node*, int>> q;

	q.push({root, 0});
	nodeHeight[0] = root->data;

	while (!q.empty()) {
		Node* curr = q.front().first;
		int currHeight = q.front().second;
		q.pop();


		nodeHeight[currHeight].push_back(curr->data);

		if (curr->left) q.push({curr->left, currHeight - 1});
		if (curr->right) q.push({curr->right, currHeight});
	}

	vector<int> res;
	for (auto num : nodeHeight)
		res.push_back(num.second);

	return res;
}