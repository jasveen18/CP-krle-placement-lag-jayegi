void findCombinations(vector<int> &a, int targetSum, int currSum,
                      vector<int> &runningVec, int idx,
                      vector<vector<int>> &res) {
	//
	if (idx == a.size())
		return;

	// Base Case
	if (currSum == targetSum) {
		res.push_back(runningVec);
		return;
	}

	// Exclude case
	findCombinations(a, targetSum, currSum, runningVec, idx + 1, res);

	// Include case
	runningVec.push_back(a[idx]);
	for (int i = idx; i < a.size(); i++) {
		if (currSum + a[i] <= targetSum) {
			findCombinations(a, targetSum, currSum + a[idx], runningVec, i, res);
		}
	}

	// Backtrack
	runningVec.pop_back();
	return;
}


vector<vector<int>> combinationSum(vector<int> &a, int b) {
	vector<vector<int>> res;
	vector<int> r;
	findCombinations(a, b, 0, r, 0, res);

	// Get unique values and sort according to format
	for (int i = 0; i < res.size(); i++) {
		sort(res[i].begin(), res[i].end());
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	return res;
}
