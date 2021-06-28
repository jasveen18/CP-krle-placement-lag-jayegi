// ** Kth Smallest Element ** //

// Problem - Given unsorted array, find the kth smallest element.
// Naive - Sort and return arr[k-1];

// Identification of heap -
// 1. k dia hai.
// 2. smallest dia hai.
// Toh heap lagega.

// Ab smallest pucha hai smallest heap lagega.

int KthSmallestElement(vector<int> &nums) {
	// Make a max heap
	priority_queue<int> maxHeap;

	for (int i = 0; i < nums.size(); i++) {
		// Element ko daalte jao, top element max hoga
		maxHeap.push(nums[i]);

		// Jaise hi size greater than k hota hai that means we don't need the top element, wo answer hoga hi ni.
		if (maxHeap.size() > k) {
			maxHeap.pop();
		}
	}

	return maxHeap.top();
}