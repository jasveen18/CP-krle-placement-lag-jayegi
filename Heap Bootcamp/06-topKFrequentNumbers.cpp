// ** Top K Frequent Numbers ** //

// Problem Statement -
// Get the top k frequent numbers

// Identification -
// 1. K dia hai.
// 2. Ek chiz ka highest / lowest puch ra hai.

// Approach - Ek hash use krenge to store the count
vector<int> topKFrequent(vector<int> &nums, int n, int k) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int , int>>> minHeap;
	unordered_map<int, int> countEl;
	vector<int> res;

	// To get the frequency
	for (int el : nums)
		countEl[el]++;

	// Now this is the main function to find the top k frequency
	for (auto el : countEl) {
		minHeap.push({el.second, el.first});

		if (minHeap.size() > k)
			minHeap.pop();
	}

	while (!minHeap.empty()) {
		res.push_back(minHeap.top().second); minHeap.pop();
	}

	return res;
}