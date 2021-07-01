/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Convert a BST to Min Heap
// 1. Make a array and store in-order traversal of the tree.
// 2. Do a pre order traversal and copy the values of the array.


void inOrderStore(Node* root, vector<int> &data) {
	if (root == NULL)
		return;

	inOrderStore(root->left, data);
	data.push_back(root->data);
	inOrderStore(root->right, data);
}


void copyThroughPreOrder(Node *root, vector<int> &data, int &idx) {
	if (root == NULL)
		return;

	root->data = data[idx]; idx++;
	copyThroughPreOrder(root->left, data, idx);
	copyThroughPreOrder(root->right, data, idx);
}


Node* convertBSTtoMinHeap(Node* root) {
	vector<int> data;
	inOrderStore(root, data);

	int idx = 0;
	copyThroughPreOrder(root, data, idx);

	return root;
}