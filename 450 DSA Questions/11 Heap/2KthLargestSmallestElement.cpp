/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the kth largest and smallest element

vector<int> findKthSmallesAndLargest(vector<int> &nums, int k) {
	int n = nums.size();
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++) {
		maxHeap.push(nums[i]);
		minHeap.push(nums[i]);

		if (maxHeap.size() > k)
			maxHeap.pop();

		if (minHeap.size() > k)
			minHeap.pop();
	}

	//       kth smallest,  kth largest
	return {maxHeap.top(), minHeap.top()};
}