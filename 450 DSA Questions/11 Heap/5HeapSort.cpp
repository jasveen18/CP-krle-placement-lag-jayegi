// ** Heap Sort ** //

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


void heapSort(vector<int> &nums, int n) {
	// Build heap function
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--)
		heapSort(nums, n, i);

	// Now extract each element one by one from heap and put it at the end
	for (int i = n - 1; i > 0; i--) {
		// Move the largest element to the end, [0] kyunki largest toh front (root) pe hota hai na
		swap(nums[0], nums[i]);

		// Call heapify to balance the new node at root
		heapify(nums, n, 0);
	}

	return;
}