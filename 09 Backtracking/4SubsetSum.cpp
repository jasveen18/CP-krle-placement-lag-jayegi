// Approach 1 - Recursion
// T - O(2^n)
// S - O(2^n)
bool isPossibleEqualPartition(int arr[], int n, int i, int currSum, int totalSum) {
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

	// Recursive Cases
	// Include the current element
	bool includeCase = isPossibleEqualPartition(arr, n, i + 1, currSum + arr[i], totalSum);

	// Exclude the current element
	bool excludeCase = isPossibleEqualPartition(arr, n, i + 1, currSum, totalSum);

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

	int currSum = 0;
	return isPossibleEqualPartition(arr, N, 0, currSum, sum);
}