// ** Frequency Sort ** //

// Problem Statement - Sort the array on the basis of frequency.
// k = n hi hai.

// One check, doesn't take into account if frequency is same. Uska comp function likh lena
vector<int> frequencySort(vector<int> &nums, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int , int>>> minHeap;
	unordered_map<int, int> countEl;
	vector<int> res;

	// To get the frequency
	for (int el : nums)
		countEl[el]++;

	// Now this is the main function to find the top k frequency
	for (auto el : countEl) {
		minHeap.push({el.second, el.first});
	}

	while (!minHeap.empty()) {
		res.push_back(minHeap.top().second); minHeap.pop();
	}

	return res;
}