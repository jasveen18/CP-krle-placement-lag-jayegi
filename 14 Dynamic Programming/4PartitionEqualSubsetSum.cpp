// ** This is what you thought and came up with ** //
// T - O(N*N)
// S - O(N*N)
bool isPossibleEqualPartition(int arr[], int n, int i, int currSum, int totalSum, vector<vector<int>> &dp) {
	// Base Cases
	// We can divide the array into 2 parts
	if (currSum == totalSum / 2)
		return true;

	// We can't divide with this configuration
	if (currSum > totalSum / 2)
		return false;

	// Array is exhausted
	if (i == n)
		return false;

	// Look up the table
	if (dp[currSum][i] != -1)
		return dp[currSum][i];

	// Recursive Cases
	// Include the current element
	bool includeCase = isPossibleEqualPartition(arr, n, i + 1, currSum + arr[i], totalSum, dp);
	dp[currSum + arr[i]][i + 1] = includeCase;

	// Exclude the current element
	bool excludeCase = isPossibleEqualPartition(arr, n, i + 1, currSum, totalSum, dp);
	dp[currSum][i + 1] = excludeCase;

	// Is this case a valid config?
	return includeCase or excludeCase;
}


int equalPartition(int N, int arr[]) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	// If sum is odd
	if (sum & 1)
		return false;

	vector<vector<int>> dp(sum + 1, vector<int>(N + 1, -1));

	int currSum = 0;
	sort(arr, arr + N, greater<int>());
	return isPossibleEqualPartition(arr, N, 0, currSum, sum, dp);
}



// ** This is what your learned ** //
// 1. First we will make a function which will tell us if targetSum can be made
//	  using some elments of the array. Return true or false.
// 2. Take the half sum and search if it can be made or not? There you go.

bool isSubsetSumPossible(vector<int> &nums, int targetSum) {
	int n = nums.size();

	// Initialization for bottom up, just like 0-1 Knapsack
	vector<vector<bool>> dp(n + 1, vector<bool> (targetSum + 1, 0));

	// Because we are looking for weight in zero size array.
	for (int j = 0; j <= targetSum; j++)
		dp[0][j] = false;
	// We are looking for zero sum in subset, so empty subset is always the answer.
	for (int i = 0; i <= n; i++)
		dp[i][0] = true;


	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= targetSum; j++) {
			// If we can include it
			if (nums[i - 1] <= j) {
//							Exclude         Include
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][targetSum];
}

bool equalPartition(vector<int> &nums) {
	int totalSum = 0;
	for (int i = 0; i < nums.size(); i++)
		totalSum += nums[i];

	// If the sum is odd, we can't divide into 2 equal parts
	if (totalSum & 1)
		return false;

	// Else see if we can pick some elements to form the array with half the sum.
	return isSubsetSumPossible(nums, totalSum / 2)
}

// Note we can also modify the bottom up appraoch of subset sum possible to top down using recursion