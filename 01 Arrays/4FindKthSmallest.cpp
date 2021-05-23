// Approach 1 - Using Priority Queue to store the first k small elements
// Time Complexity - O(N + K Log K)
// Space Complexity - O(K)
int kthSmallest(int arr[], int n, int k) {
	priority_queue<int> smallestK;

	for (int i = 0; i < n; i++) {
		// First store the top k elements
		if (smallestK.size() < k) {
			smallestK.push(arr[i]);
			continue;
		}

		// Swap the top element (largest) if some element is smaller that it.
		if (smallestK.top() > arr[i]) {
			smallestK.pop();
			smallestK.push(arr[i]);
		}
	}

	// Return the Kth smallest element
	return smallestK.top();
}