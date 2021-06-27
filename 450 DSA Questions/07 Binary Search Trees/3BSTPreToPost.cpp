/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert the given pre order to post order


void postOrderTraversal(Node* root, vector<int> &data) {
	if (root == NULL)
		return;

	postOrderTraversal(root->left, data);
	postOrderTraversal(root->right, data);
	data.push_back(root->data);
}


//Function that constructs BST from its preorder traversal.
Node* constructTree(int pre[], int size, int start, int end, int &preIndex) {
	// Base Case -
	if (preIndex == size or pre[preIndex] < start or pre[preIndex] > end)
		return NULL;

	int val = pre[preIndex++];
	Node* root = newNode(val);
	root->left = constructTreePreorder(pre, size, start, val, preIndex);
	root->right = constructTreePreorder(pre, size, val, end, preIndex);

	return root;
}

vector<int> preToPost(int pre[], int size) {
	int index = 0;
	Node* root = constructTree(pre, size, INT_MIN, INT_MAX, index);

	vector<int> postOrder;
	postOrderTraversal(root, data);

	return postOrder;
}