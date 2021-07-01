/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Merge 2 max heaps
// Implementation of heap sort -
void heapifyMax(vector<int> &nums, int n, int idx) {
	// Let parent be largest now
	int largestNow = idx;
	// Take children indexes
	int leftChild = 2 * idx + 1;
	int rightChild = 2 * idx + 2;

	// Now we need to find the largest of the three
	// If left child is greater
	if (leftChild < n and nums[leftChild] > nums[largestNow])
		largestNow = leftChild;

	// If right child is greatest
	if (rightChild < n and nums[rightChild] > nums[largestNow])
		largestNow = rightChild;

	// If largest is not parent(root)
	if (largestNow != idx) {
		// Uss node ko parent bana do
		swap(nums[idx], nums[largestNow]);

		// Recursively call the sub-tree
		heapify(nums, n, largestNow);
	}

	return;
}


vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
	for (int i = 0; i < m; i++) {
		a.push_back(b[i]);
	}

	// First leaf node-
	int startIdx = (n + m) / 2 - 1;
	for (int i = startIdx; i >= 0; i--)
		heapifyMax(a, (n + m), i);

	return a;
}