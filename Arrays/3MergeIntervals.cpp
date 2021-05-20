// Merge the overlapping intervals
// Time Complexity - O(N Log N)
// Space Complexity - O(N)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();

	// Sort by arriving time
	sort(intervals.begin(), intervals.end(), [](auto & a, auto & b) {
		if (a[0] == b[0])
			return a[1] < b[1];

		return a[0] < b[0];
	});

	// Start with first event
	vector<vector<int>> res;
	int startAt = intervals[0][0];
	int endAt = intervals[0][1];

	for (int i = 1; i < n; i++) {
		if (intervals[i][0] <= endAt) {			  // If event is overlapping, merge
			endAt = max(endAt, intervals[i][1]);
		} else {								  // Start new event
			res.push_back({startAt, endAt});
			startAt = intervals[i][0];
			endAt = intervals[i][1];
		}
	}

	// Push the last event
	res.push_back({startAt, endAt});
	return res;
}