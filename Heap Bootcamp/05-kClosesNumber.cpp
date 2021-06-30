// ** K Closest Number ** //

// Problem Statement - Given an array, k and x. Find k numbers closest to x.

// Identification -
// k dia hai.
// closest (smallest) dia hai.


// Approach -
// We will have something else as key. abs(nums[i] - x)

vector<int> kClosestNumber(vector<int> &nums, int n, int k, int x) {
	priority_queue<pair<int, int>> maxHeap;

	for (int i = 0; i < n; i++) {
		maxHeap.push({abs(nums[i] - x), nums[i]});

		if (maxHeap.size() > k)
			maxHeap.pop();
	}

	// Store the left over values now. That is the answer
	vector<int> res;
	while (!maxHeap.empty()) {
		res.push_back(maxHeap.top().second);
		maxHeap.pop();
	}

	return res;
}