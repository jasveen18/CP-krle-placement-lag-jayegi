// Segment Trees | Data Structure for Ranged Based Queries + Updates
// Useful when n is large and we can't use DP to precompute.
// Also, we can't do updates in precomputation.
// Based on Divide and Conquer.

// We will array like datastructe to store the tree.
// Parent i, Children at 2i and 2i+1.

// For an array N we need (4*N + 1) space.


// O(N) Time
void buildTree(int arr[], int s, int e, int *tree, int index) {
	// Base Case - The range only has one element.
	if (s == e) {
		tree[index] = arr[s];
		return;
	}

	// Recursive Case
	int mid = s + (e - s) / 2;
	// Left Sub-Tree (Child) - stored at 2*i
	buildTree(a, s, mid, tree, 2 * index);
	// Right Sub-Tree (Child) - stored at 2*i+1
	buildTree(a, mid + 1, e, tree, 2 * index + 1);

	// Put the curr element
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}


void segementTree(int arr[], int n) {
	int *tree = new int[4 * n + 1];
	buildTree(arr, 0, n - 1, tree, 1);
}

