// *** Maximum Number of Deletions in a String to make it a Palindrome *** //

// 1. Problem Statement -
// Ek string de rakhi hogi, kuch insertions krna hai.
// Make it a palindrome in min number of insertions.

// 2. Similarity -
// Inp same as LPS / number of deletions
// Output format same as LPS / number of deletions
// Question bhi almost same hi hai / for deletions toh same hi hai.

//  LPS => 1 / number of insertion
// Therefore, we will the take LPS of the string, and baaki chars ka pairs bana denge.

// Literally same chiz
int minInsertionsForPalindrome(stirng x, int n) {
	// Delete the chars other than LPS
	return n - longestPalindromicSubseq(x, n);
}


int longestPalindromicSubseq(string x, int n) {
	// Take reverse of string a, that is your second string(b).
	string y = reverse(x.begin(), x.end());

	// This is the answer for longest palindromic subseq.
	return longestCommonSubseqLen(x, y, n, n);
}


int longestCommonSubseqLen(string x, string y, int n, int m) {
	// Initialization
	int dp[n + 1][m + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	// Build up the dp -> if same then add one
	// else, get the max from both pointers.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	return dp[n][m];
}