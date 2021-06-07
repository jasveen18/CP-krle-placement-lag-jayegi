// Approach 1 - Same as 2nd approach of find the median
// Time Complexity - O(32 * N * Log N)
// Space Complexity - O(1)
int kthSmallest(int mat[MAX][MAX], int n, int k) {
	// Get the min and max el for search space
	int minEl = mat[0][0], maxEl = mat[n - 1][n - 1];

	// Binary search
	while (minEl < maxEl) {
		int midEl = minEl + (maxEl - minEl) / 2;
		int smallCount = 0;

		// Count the number of numbers smaller than mid
		for (int i = 0; i < n; i++) {
			smallCount += upper_bound(mat[i], mat[i] + n, midEl) - mat[i];
		}

		if (smallCount < k)
			minEl = midEl + 1;
		else
			maxEl = midEl;
	}

	return minEl;
}