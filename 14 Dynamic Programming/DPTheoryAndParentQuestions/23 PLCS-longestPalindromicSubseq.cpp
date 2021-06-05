// *** Longest Palindromic Subsequence *** //

// 1. Problem Statement
// String mein se, longest palindromic subsequence nikalni hai.
// Return the length of that

// 2. Similarity -
// Dp hai?
// Hnn, longest maang ra hai, optimal chiz.
// LCS kaise phir?
// inp -> ni match ni krra
// que -> subsequence hi maang ra hai
// out -> integer length, hnn matches.

// Ab input chaiye,
// b string kaha hai? Maybe derive ho? or redundant ho?

// Palindrome hai, toh ek baar reverse of A lekr dekhte hai.
// Hnn if B is reverse of A, then we have the answer by just using LCS.

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

// Note - For printing the palindromic subseq bhi, we can use printLCS there.