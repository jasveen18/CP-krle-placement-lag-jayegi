// TLE Solution - (N!)
void findMaximumBacktracking(string &str, int k, int idx, int swaps, string &maxNum) {
	// Base Case
	if (swaps == k or idx == str.size()) {
		// cout << str << " " << maxNum << " " << swaps << endl;
		if (str > maxNum)
			maxNum = str;
		return;
	}

	// Recursive Case
	for (int i = idx; i < str.size(); i++) {
		swap(str[i], str[idx]);
		if (i == idx)
			findMaximumBacktracking(str, k, idx + 1, swaps, maxNum);
		else
			findMaximumBacktracking(str, k, idx + 1, swaps + 1, maxNum);

		// Backtrack
		swap(str[i], str[idx]);
	}

	return;
}