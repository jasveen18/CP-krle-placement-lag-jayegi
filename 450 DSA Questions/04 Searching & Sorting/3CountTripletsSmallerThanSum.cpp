/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - find count of triplets with the sum smaller than the given sum value X.

// Sort and 2 pointer
long long countTriplets(long long arr[], int n, long long sum) {
	sort(arr, arr + n);
	int ans = 0;

	// 2 pointer approach
	for (int i = 0; i < n; i++) {
		int start = i + 1, end = n - 1;
		while (start < end) {
			int sumHere = arr[i] + arr[start] + arr[end];
			if (sumHere < sum) {
				ans += end - start; // Coz utne numbers shii answer result krenge
				start++;
			} else
				end--;
		}
	}

	return ans;
}