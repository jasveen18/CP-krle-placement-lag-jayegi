/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print all the k-sum path of the binary tree.

// Input : k = 5
//         Root of below binary tree:
//            1
//         /     \
//       3        -1
//     /   \     /   \
//    2     1   4     5
//         /   / \     \                    
//        1   1   2     6

// Output :
// 3 2
// 3 1 1
// 1 3 1
// 4 1
// 1 -1 4 1
// -1 4 2
// 5
// 1 -1 5

// This would have been easy if we were considering every node from root.
// Ek single pre-order traversal pe ho jaata. But here, every node can be considered as root.

// Idea is to traverse pre-order(top down), we will check at each node for sum = k.
void printKPath(Node* root, int k) {
	vector<int> path;
	printKPathHelper(root, path, k);
}


void printKPathHelper(Node* root, vector<int> &path, int k) {
	if (root == NULL)
		return NULL;

	// Push current node to the path
	path.push_back(root->data);

	// Preorder traversal
	printKPathHelper(root->left, path, k);
	printKPathHelper(root->right, path, k);

	// Now check any path here which will sum to 'k'.
	int sumHere = 0;
	for (int j = path.size() - 1; j >= 0; j--) {
		sumHere += path[j];

		// If found, then print. Don't break coz aage aur mil skta hai with negative numbers.
		if (sumHere == k)
			printVector(path, j);	// This function will print path[j], path[j+1], ... path[path.size()-1]
	}

}