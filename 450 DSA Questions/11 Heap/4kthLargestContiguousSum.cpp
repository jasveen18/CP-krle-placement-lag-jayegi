/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the Kth largest contiguous sum array.

int kthLargestContiguousSum(vector<int> &nums, int n) {
	priority_queue<int> minHeap;

	// Generate all the contiguous sum arrays
	for (int i = 0; i < n; i++) {
		int sumHere = 0;
		for (int j = i; j < n; j++) {
			sumHere += nums[j];
		}

		minHeap.push(sumHere);
		if (minHeap.size() > k)
			minHeap.pop();
	}

	return minHeap.top();
}