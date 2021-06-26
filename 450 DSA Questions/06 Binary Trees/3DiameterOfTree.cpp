/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to return the diameter of a Binary Tree.

// Find the diameter using height
int findDiameterRecursive(Node* root, int &diameter) {
	// Base Case -
	if (root == NULL)
		return 0;

	// Recursive Case -
	int heightLeft = findDiameterRecursive(root->left, diameter);
	int heightRight = findDiameterRecursive(root->right, diameter);

	diameter = max(diameter, heightLeft + heightRight + 1);
	return max(heightLeft, heightRight) + 1;
}

int diameter(Node* root) {
	int diameter = 0;
	findDiameterRecursive(root, diameter);

	return diameter;
}