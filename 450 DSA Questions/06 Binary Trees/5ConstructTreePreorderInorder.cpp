/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal.

Node* buildTreeHelper(int inorder[], int preorder[], int idxStart, int idxEnd, int &preIndex) {
	// Base Case -
	if (idxStart > idxEnd)
		return NULL;

	// 1. Make a new node for the root and increment the index for preorder
	Node* root = new Node(preorder[preIndex]);
	preIndex++;

	// Find this value in the inorder array, we can optimize find operation using hash set O(1)
	int inIndex;
	for (int i = idxStart; i <= idxEnd; i++) {
		if (inorder[i] == root->data) {
			inIndex = i;
			break;
		}
	}

	// Recursive Case for the children -
	root->left = buildTreeHelper(inorder, preorder, idxStart, inIndex - 1, preIndex);
	root->right = buildTreeHelper(inorder, preorder, inIndex + 1, idxEnd, preIndex);
	return root;
}


Node* buildTree(int in[], int pre[], int n) {
	int preIdx = 0;
	return buildTreeHelper(in, pre, 0, n - 1, preIdx);
}