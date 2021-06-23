/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the count of subsets having sum between a and b.
// Meet me in the middle optimization.

long long int x[40000005], y[40000005];

void createSubArraySum(vector<long long int> &a, long long int x[], long long int n, long long int c) {
	for (long long int i = 0; i < (1 << n); i++) {
		long long int s = 0;
		for (long long int j = 0; j < n; j++)
			if (i & (1 << j))
				s += a[j + c];
		x[i] = s;
	}
}


long long int countSubsetSum(vector<long long int> &arr, long long int n, long long int a, long long int b) {
	// Compute the subset sum of both halves
	createSubArraySum(arr, x, n / 2, 0);
	createSubArraySum(arr, y, n - n / 2, n / 2);

	long long int size_x = 1 << (n / 2);
	long long int size_y = 1 << (n - n / 2);

	// Sort the 2nd array so that we can do binary search on this.
	sort(y, y + size_y);

	long long int ans = 0;

	// Traverse over all the elements of x and do BS to find valid pairs.
	for (long long int i = 0; i < size_x; i++) {
		long long int minSum = a - x[i];
		long long int maxSum = b - x[i];

		long long int upp = upper_bound(y, y + size_y, maxSum) - y;
		long long int low = lower_bound(y, y + size_y, minSum) - y;

		ans += upp - low;
	}

	return ans;
}