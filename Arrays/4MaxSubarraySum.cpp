//Function to find the sum of contiguous subarray with maximum sum.
// Kadane's Algorithm
// Time Complexity - O(N)
// Space Complexity - O(1)
int maxSubarraySum(int arr[], int n) {
	int maxSoFar = arr[0];
	int maxGlobal = arr[0];

	for (int i = 1; i < n; i++) {
		maxSoFar = max(maxSoFar + arr[i], arr[i]);
		maxGlobal = max(maxSoFar, maxGlobal);
	}

	return maxGlobal;
}