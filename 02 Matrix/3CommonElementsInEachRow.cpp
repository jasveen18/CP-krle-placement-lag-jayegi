void printCommonElements(vector<vector<int>> &matrix, int n, int m) {
	unordered_map<int, int> seenElements;

	// Put all the elements of first row.
	for (int i = 0; i < m; i++) {
		seenElements[matrix[0][i]]++;
	}

	// Start checking for next rows
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// If it is present in all other rows earlier
			if (seenElements[matrix[i][j]] == i) {
				seenElements[matrix[i][j]]++;
			}
		}
	}

	// Print the common elements
	for (auto el : seenElements) {
		if (el.second == n) {
			cout << el.first << " ";
		}
	}
}