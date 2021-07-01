// ** Heap Implementation ** //

// ** Max Heap ** //

// build Heap function, main driver function.
void buildHeapMax(vector<int> &nums, int n) {
	// Index of first non-leaf node.
	int startIdx = (n / 2) - 1;

	// Perform reverse level-order traversal
	// Mtlb ki right to left traverse krenge
	for (int i = startIdx; i >= 0; i--) {
		heapify(nums, n, i);
	}
}


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


// ** Min Heap ** //
void buildHeapMin(vector<int> &nums, int n) {
	// First non-leaf node
	int startIdx = (n / 2) - 1;

	// Reverse reverse level order traversal
	for (int i = startIdx; i >= 0; i--) {
		heapifyMin(nums, n, i);
	}
}


void heapifyMin(vector<int> &nums, int n, int idx) {
	// Smallest is assumed to be parent here
	int smallestNow = idx;
	int leftChild = 2 * idx + 1;
	int rightChild = 2 * idx + 2;

	if (leftChild < n and nums[leftChild] < nums[smallestNow])
		smallestNow = leftChild;

	if (rightChild < n and nums[rightChild] < nums[smallestNow])
		smallestNow = rightChild;

	if (smallestNow != idx) {
		swap(nums[smallestNow], nums[idx]);

		heapifyMin(nums, n, smallestNow);
	}
}