// Kadane's Algroithm
// In constant space
int maxSubarraySum(int arr[], int n) {
	int minSoFar = arr[0];
	int minEnding = arr[0];

	for (int i = 1; i < n; i++) {
		minSoFar = min(arr[i] + minSoFar, arr[i]);
		minEnding = min(minEnding, minSoFar);
	}

	return minEnding;
}