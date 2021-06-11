int lcs(int x, int y, int s1[], int s2[]) {
	// Initialization
	int dp[x + 1][y + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= x; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= y; j++)
		dp[0][j] = 0;

	// Build up the dp
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[x][y];
}


int longestSubsequence(int n, int a[]) {
	// Get a new array

	// Set to remove duplicates and sort the values.
	set<int> removeDup(a, a + n);
	int b[removeDup.size() + 1];
	int i = 0;
	for (auto el : removeDup) {
		b[i++] = el;
	}

	// Do LCS on normal array and sorted array.
	return lcs(n, removeDup.size(), a, b);
}


// Approach 2 - Here we will have LIS till the index i, also TLE
// T - O(N*N)
// S - O(N)
int longestSubsequence(int n, int a[]) {
	// Initialize the dp
	vector<int> dp(n + 1, 0);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j - 1])
				dp[i] = max(dp[i], dp[j]);
		}

		dp[i]++;
	}

	// Get the longest subsequence
	int longestSubseq = 0;
	for (int i = 0; i <= n; i++)
		longestSubseq = max(longestSubseq, dp[i]);

	return longestSubseq;
}


// Approach 3 - We will use the index of dp as length of the LIS.
// T - O(N*N)
// S - O(N)

int longestSubsequence(int n, int a[]) {
	// Initialize a dp
	// i, i+1 ke beech m jo bhi number hoga ussi m number lie krega.
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[j] < a[i] and a[i] < dp[j + 1])
				dp[j + 1] = a[i];
		}
	}

	// Get the longest subsequence
	int longestSubseq = 0;
	int i = 0;
	for (i = 0; i <= n; i++) {
		if (dp[i] != INT_MAX)
			longestSubseq = i;
	}

	// 	for (int i = 1; i <= n; i++)
	// 		cout << dp[i] << " ";
	// 	cout << endl;

	return longestSubseq;
}


// Approach 4 - Now we will use binary search along with the previous app
// T - O(N Log N)
// S - O(N)
// Accepted Solution.
int longestSubsequence(int n, int a[]) {
	// Initialize a dp
	// i, i+1 ke beech m jo bhi number hoga ussi m number lie krega.
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = INT_MIN;

	for (int i = 0; i < n; i++) {
		int position = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

		if (dp[position - 1] < a[i] and a[i] < dp[position])
			dp[position] = a[i];
	}

	// Get the longest subsequence
	int longestSubseq = 0;
	for (int i = 0; i <= n; i++) {
		if (dp[i] != INT_MAX)
			longestSubseq = i;
	}

	return longestSubseq;
}