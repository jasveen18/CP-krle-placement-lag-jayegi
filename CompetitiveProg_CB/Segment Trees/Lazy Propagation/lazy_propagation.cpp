// Lazy Propogation in Segment Trees
// --------------------------------------

// - Optimisation to do "Range Updates" in Segment Tree in O(LogN) time
// - Idea: Postpone the updates to descendants of a Node until
// 		the descendants themselves need to be accessed.


#include<iostream>
using namespace std;

// To store the lazy values
int lazy[10000] = {0};

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
	// Resolve the lazy values
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (ss != se) {
			lazy[2 * index] = lazy[index];
			lazy[2 * index + 1] = lazy[index];
		}
		// Clear the lazy value at current node
		lazy[index] = 0;
	}

	// Base Case
	// No Overlap
	if (ss > r or l < se) {
		return;
	}

	// Recursive Case
	// Complete Overlap
	if (ss >= l and se <= r) {
		tree[index] += inc;

		// Create the lazy value for childre
		if (ss != se) {
			lazy[2 * index] += inc;
			lazy[2 * index + 1] += inc;
		}

		return;
	}

	// Partial Overlap
	int mid = (ss + se) / 2;
	updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
	updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}


int queryLazy(int *tree, int ss, int se, int qs, int qe, int index) {
	// Resolve the lazy values
	if (lazy[index] != 0) {
		tree[index] += lazy[index];
		if (ss != se) {
			lazy[2 * index] = lazy[index];
			lazy[2 * index + 1] = lazy[index];
		}
		// Clear the lazy value at current node
		lazy[index] = 0;
	}

	// No Overlap
	if (ss > qq or se < qs) {
		return INT_MAX;
	}

	// Complete Overlap
	if (ss >= qs and se <= qe) {
		return tree[index];
	}

	// Partial Overlap
	int mid = (s + e) / 2 ;
	int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
	int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);
	return min(left, right);
}


// Same as segment trees.
void buildTree(int *a, int s, int e, int *tree, int index) {
	if (s == e) {
		tree[index] = a[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * index);
	buildTree(a, mid + 1, e, tree, 2 * index + 1);
	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
	return;
}