// Point Update -
// i -> i+10;


// O(LogN)
void updateTree(int *tree, int ss, int se, int i, int increment, int index) {
	// Case where i is out of bounds -
	if (i > se or i < ss) {
		return;
	}

	// We reached the leaf node.
	if (ss == se) {
		tree[index] += increment;
		return;
	}

	// Traversal - Bottom Up Now
	int mid = (ss + se) / 2;
	updateTree(tree, ss, mid, i, increment, 2 * index);
	updateTree(tree, mid + 1, se, i, increment, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}