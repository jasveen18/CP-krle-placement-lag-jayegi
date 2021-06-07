// *** Palindrome Partitioning *** //

// 1. Problem Statement -
// We have to divide a given string in such a way that each part is a palindrome.
// Find the min number of paritions that you have to do such that all partitions is a palindrome.
// Worst Case? -> n-1 partitions krdo. Pura string ek ek char pe divide ho jaega, toh palindrome hai hi.

// 2. Identification? ->
// Partitions krni hai, kaha pe partition kre pta ni hai.
// Toh sab check kr lenge.

// Format -
// 1. Find i, j
// 2. Find base condition
// 3. k loop ko find kro, start and end of loop
// 4. temp ans pe jo function chaiye wo batao


// Solve -
// 1. i = 0, j = size-1. Valid hai, koi dikkat ni hai.
// 2. i >= j or isPalindrome(s, i, j) then return 0;
// 3. i to k, k+1 to j. start = i, end = j-1
// 4. min function chaiye as that is required in the question.


// Top Down DP
int palindromePartitioning(string s, int i, int j) {
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
		int firstPart = palindromePartitioning(s, i, k);
		int secondPart = palindromePartitioning(s, k + 1, j);

		// Add 1, as ek partition toh kra hai na.
		tempAns = 1 + firstPart + secondPart;
		minPartitions = min(tempAns, minPartitions);
	}

	return dp[i][j] = minPartitions;
}


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



