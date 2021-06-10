// There are 3 cases -

// 1. Full overlap. Where your range overlaps completely with
// one of the ranges defined by the tree. We just return the
// element stored there.

// 2. Partial overlap. When the range lies in 2 or more elements.
// Range lie partially on one element.

// 3. No overlap. Just return INF.


// O(logN)
int performQuery(int *tree, int ss, int se, int qs, int qe, int index) {
	// qs - query start, qe - query end
	// ss - element range start, se - end
	// index - current index
	// tree - already built segment tree.

	// Complete Overlap
	if (ss >= qs and se <= qe)
		return tree[index];

	// No Overlap
	if (qe < ss or qs > se)
		return INT_MAX;

	// Partial Overlap
	int mid = (ss + se) / 2;
	int left = performQuery(tree, ss, mid, qs, qe, 2 * index);
	int right = performQuery(tree, mid + 1, se, qs, qe, 2 * index + 1);

	return min(left, right);
}