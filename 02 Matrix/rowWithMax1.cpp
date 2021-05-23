// Approach 1 - Brute Force
// Time Complexity - O(m * n)
// Space Complexity - O(1)
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	// Traverse the first element of each array
	// if we find 1, return that, since sorted.
	// if not, move to next element of each row.
	for (int start = 0; start < m; start++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][start] == 1)
				return i;
		}
	}

	return -1;
}