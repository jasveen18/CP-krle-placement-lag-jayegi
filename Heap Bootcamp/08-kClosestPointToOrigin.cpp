// ** K Closest Point to Origin ** //

// Problem Statement - Given array of points, find k closest points.

// Identification -
// 1. k dia hai.
// 2. closest puch ra hai.


int distanceFormula(pair<int, int> a) {
	return a.first * a.first + a.second * a.second;
}

vector<pair<int, int>> kClosestPoints(vector<pair<int, int>> &points, int n, int k) {
	priority_queue < pair<int, pair<int, int>> maxHeap;
	// Key ke jagah sqrt(x^2 + y^2) ke jagah pe sqrt ni daalte hai, answer toh shii hi aayega
	// since relative.

	for (int i = 0; i < n; i++) {
		maxHeap.push({distanceFormula(nums[i]), nums[i]});

		if (maxHeap.size() > k) {
			maxHeap.pop();
		}
	}

	vector<pair<int, int>> res;
	while (!maxHeap.empty()) {
		res.push_back(maxHeap.top().second);
		maxHeap.pop();
	}

	return res;
}