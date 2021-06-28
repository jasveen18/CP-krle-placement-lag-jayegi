// ** K Largest Elements ** //

// Problem - Given unsorted array, find the k largest elements.
// Naive - Sort and return answer;

// Identification of heap -
// 1. k dia hai.
// 2. largest dia hai.
// Toh heap lagega.

// Ab largest pucha hai toh max heap lagega.
vector<int> kLargest(int arr[], int n, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++) {
		// Elements daalte jao
		minHeap.push(arr[i]);

		// If size is > k, mtlb top wala element contribute ni krega.
		if (minHeap.size() > k) {
			minHeap.pop();
		}
	}

	vector<int> res;
	while (minHeap.size() > 0) {
		res.push_back(minHeap.top()); minHeap.pop();
	}

	reverse(res.begin(), res.end());
	return res;
}