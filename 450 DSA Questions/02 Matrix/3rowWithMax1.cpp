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


// Approach 2 - Binary Search
// Time Complexity - O(m + n)
// Space Complexity - O(1)
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	int col = m - 1;
	int row = n - 1;
	int resIndex = -1;

	// Get the max row by binary search
	while (col >= 0 and row >= 0) {
		if (arr[row][col] == 1) {
			resIndex = row;
			col--;
		} else {
			row--;
		}
	}

	// To pick the row index that appears first
	if (col == -1 or row == -1) {
		for (int i = n - 1; i >= 0; i--) {
			if (col + 1 < m and arr[i][col + 1] == 1)
				resIndex = i;
		}
	}

	return resIndex;
}