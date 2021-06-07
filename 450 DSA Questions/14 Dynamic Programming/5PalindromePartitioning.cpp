int palindromePartitioningOptimization(string s, int i, int j) {
	// Base Case
	if (i >= j)
		return 0;

	// Look up the table
	if (dp[i][j] != -1)
		return dp[i][j];

	// This will be here, don't put it at top ni toh TLE.
	// Check for palindrome
	if (isPalindrome(s, i, j))
		return 0;

	int minPartitions = INT_MAX;
	// Recursive Case
	for (int k = i; k < j; k++) {
		// The thing is if we see that the left part is making a palindrome then only
		// we need to run the recursion. as if it is not making palindrome then answer is not
		// there. As the recursion will calculate it while backtracking.
		if (isPalindrome(s, i, k)) {
			int secondPart = palindromePartitioning(s, k + 1, j);
			// Add 1, as ek partition toh kra hai na.
			int tempAns = 1 + secondPart;
			minPartitions = min(tempAns, minPartitions);
		}
	}

	return dp[i][j] = minPartitions;
}



bool isPalindrome(string s, int i, int j) {
	if (i == j)
		return true;
	if (i > j)
		return true;

	while (i < j) {
		if (s[i] == s[j]) {
			i++; j--;
		} else {
			return false;
		}
	}

	return true;
}
