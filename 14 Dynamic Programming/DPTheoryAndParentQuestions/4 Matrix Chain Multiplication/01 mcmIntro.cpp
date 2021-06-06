// *** Matrix Chain Multiplication *** //

// 1. MCM
// 2. Printing MCM
// 3. Evaluate Expression to True / Boolean Parenthesis
// 4. Min / Max Value of an Expression
// 5. Palindrome Partitioning
// 6. Scramble String
// 7. Egg Dropping Problem

// Format -

// Given string or array.
// We have to break it in two parts and then call the function for the two parts.
// Jo answers aayenge usse ans calculate krni hai.

// We try to break the it at every point by iterating over it.

// General Format ka code - recursive:
int mcmSolve(int arr[], int i, int j) {
	// Base Case
	if (i > j)	// This may be different
		return 0;

	// Thode mode variations honge in start of i, end of k, ye sab.
	for (int k = i; k < j; k++) {
		// Calculate temporary answer

		// 						yaha pe '+' aayega ya kya aayega, depends on question
		int tempAns = mcmSolve(arr, i, k) + mcmSolve(arr, k + 1, j);

		// ans = koi function laga kr on tempAns.
	}

	return ans;
}