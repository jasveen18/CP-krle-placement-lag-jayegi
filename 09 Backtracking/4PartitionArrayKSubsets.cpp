// Time limit exceeded solution.
bool doKPartitions(int a[], int n, int idx, vector<vector<int>> &nums) {
	// Base Case
	if (idx == n) {
		int sumHere = 0;
		for (int i = 0; i < nums[0].size(); i++)
			sumHere += nums[0][i];

		int prevSum = sumHere;

		bool isPossible = true;
		for (int i = 1; i < nums.size(); i++) {
			sumHere = 0;

			for (int j = 0; j < nums[i].size(); j++) {
				sumHere += nums[i][j];
			}
			if (sumHere != prevSum) {
				isPossible = false;
				break;
			}
		}

		return isPossible;
	}


	// Recursive Case
	// Either to include the current element in our kth basket or not.
	for (int i = 0; i < nums.size(); i++) {
		nums[i].push_back(a[idx]);
		bool isPossibleToFit = doKPartitions(a, n, idx + 1, nums);

		if (isPossibleToFit)
			return true;

		nums[i].pop_back();
	}

	return false;
}


bool isKPartitionPossible(int a[], int n, int k) {
	vector<vector<int>> nums(k);
	// cout << nums.size();

	return doKPartitions(a, n, 0, nums);
}