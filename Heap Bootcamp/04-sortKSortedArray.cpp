// ** Sort a nearly sorted (k) array ** //

// Problem Statement -
// Given an unsorted array, if you sort it and compare it with original array.
// Every element will be 'k' position away only. k ahead or behind.
// Sort the array.

// Naive - Sort the array

// Identification -
// 1. K dia hai.
// 2. sorting ka baat hua hai, toh smalles / largest

// Approach -
// Use a heap to store the values, toh O(N Log N) -> O(N Log K)

void sortKSorted(vector<int> &nums) {
	int n = nums.size();
	priority_queue<int, vector<int>, greater<int>> minHeap;

	// This is the real index of array jaha pe replace krenge.
	// i is for 'k' ahead.
	int j = 0;
	for (int i = 0; i < n; i++) {
		minHeap.push(arr[i]);

		if (minHeap.size() > k) {
			nums[j++] = minHeap.top();
			minHeap.pop();
		}
	}


	while (!minHeap.empty()) {
		nums[j++] = minHeap.top();
		minHeap.pop();
	}

	return;
}