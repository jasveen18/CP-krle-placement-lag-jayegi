// Time Complexity - O(N)
// Space Complexity - O(1)
int sb(int arr[], int n, int x) {
	int minSubarrayLen = INT_MAX;
	int start = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		// Pull start as far as we can
		while (sum - arr[start] > x) {
			sum -= arr[start];
			start++;
		}

		// Take the length of subarray.
		if (sum > x) {
			minSubarrayLen = min(minSubarrayLen, i - start + 1);
		}
	}

	return minSubarrayLen;
}