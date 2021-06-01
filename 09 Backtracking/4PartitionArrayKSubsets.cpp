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


// -------------------------------
// Accepted Time Complexity - O(N * 2^N)

bool doKPartitions(int a[], int n, int currSum, int targetSum,
                   vector<int> &visited,  int k, int nextIdx) {
	// Base Case - we were able to fit all the cases
	if (k == 0)
		return true;

	// Base Case - if curr sum is equal to target, then we found a group
	if (currSum == targetSum) {
		return doKPartitions(a, n, 0, targetSum, visited, k - 1, 0);
	}

	// Recursive Case
	for (int i = nextIdx; i < n; i++) {
		if (!visited[i] && currSum + a[i] <= targetSum) {
			visited[i] = 1;
			bool canWeDoSubprob = doKPartitions(a, n, currSum + a[i], targetSum, visited, k, i + 1);

			if (canWeDoSubprob)
				return true;
		}

		// Backtracking for false case
		visited[i] = 0;
	}

	return false;
}


bool isKPartitionPossible(int a[], int n, int k) {
	vector<int> visited(n, 0);
	int sumOfAllElements = 0;
	int maxNum = -1;

	for (int i = 0; i < n; i++) {
		sumOfAllElements += a[i];
		maxNum = max(maxNum, a[i]);
	}

	// Pruning
	if (sumOfAllElements % k != 0 || maxNum > sumOfAllElements / k)
		return false;

	return doKPartitions(a, n, 0, (sumOfAllElements / k), visited, k, 0);
}