/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given 2 BST, count pairs whose sum equal x.

// Approach 1 -
// T - O(N Log N) | S - O(N)
void inOrderTraversal(Node* root, vector<int> &data) {
	if (root == NULL)
		return;

	inOrderTraversal(root->left, data);
	data.push_back(root->data);
	inOrderTraversal(root->right, data);
}

// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x) {
	vector<int> data1;
	vector<int> data2;

	inOrderTraversal(root1, data1);
	inOrderTraversal(root2, data2);

	int ans = 0;

	for (int i = 0; i < data1.size(); i++) {
		if (binary_search(data2.begin(), data2.end(), (x - data1[i])))
			ans++;
	}

	return ans;
}


// Approach 2 - Binary search tree hai toh binary search kyun krna hai? LOL.
// T - O(N log N) | S - O(1)
bool searchInBST(Node* root, int key) {
	if (root == NULL)
		return false;

	while (root != NULL and root->data != key) {
		if (root->data > key)
			root = root->left;
		else
			root = root->right;
	}

	return root != NULL;
}


void countPairsHelper(Node* root1, Node* root2, int &ans, int x) {
	if (root1 == NULL)
		return;

	countPairsHelper(root1->left, root2, ans, x);

	// Operations
	if (searchInBST(root2, x - root1->data))
		ans++;

	countPairsHelper(root1->right, root2, ans, x);
}


int countPairs(Node* root1, Node* root2, int x) {
	int ans = 0;
	countPairsHelper(root1, root2, ans, x);
	return ans;
}