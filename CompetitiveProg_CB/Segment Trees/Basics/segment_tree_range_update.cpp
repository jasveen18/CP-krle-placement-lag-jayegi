// Range Update -
// Values from l to r are updated by x.

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {
	// Out of bounds - No overlap
	if (l > se or r < ss)
		return;

	// Leaf Node
	if (ss == se) {
		tree[index] += inc;
		return;
	}

	// Recursive Case
	int mid = (ss + se) / 2;
	updateRange(tree, ss, mid, l, r, inc, 2 * index);
	updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

	tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}