/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Evaluate expression to true
int dp[155][155][2];
// dp.clear(); in main function kr do. just in case.
int booleanParenthesization(string s, int i, int j, bool isTrue) {
	// Make the key for this function call
	if (dp[i][j][isTrue] != -1)
		return dp[i][j][isTrue];

	int mod = 1e3 + 3;

	// Base Case
	if (i > j)
		return false;
	if (i == j) {
		if (isTrue == true)
			return dp[i][j][isTrue] = s[i] == 'T' ? 1 : 0;
		else
			return dp[i][j][isTrue] = s[i] == 'F' ? 1 : 0;
	}

	// Recursive Case -
	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		// Find the number of ways considering all ways.
		int trueInLeft = booleanParenthesization(s, i, k - 1, true);
		int falseInLeft = booleanParenthesization(s, i, k - 1, false);
		int trueInRight = booleanParenthesization(s, k + 1, j, true);
		int falseInRight = booleanParenthesization(s, k + 1, j, false);

		// The operator that we have to evaluate here.
		char operatorAtK = s[k];

		if (operatorAtK == '&') {
			if (isTrue) { // This means we have to find true with AND operator
				// there is only possiblity when both are true
				ans += (trueInLeft * trueInRight) % mod;
			} else { // We have to find false with AND operator
				ans += (falseInLeft * trueInRight) % mod;
				ans += (trueInLeft * falseInRight) % mod;
				ans += (falseInLeft * falseInRight) % mod;
			}
		}

		if (operatorAtK == '|') {
			if (isTrue) { // This means we want the expression to be true with OR operator
				ans += (falseInLeft * trueInRight) % mod;
				ans += (trueInLeft * falseInRight) % mod;
				ans += (trueInLeft * trueInRight) % mod;
			} else {
				ans += (falseInLeft * falseInRight) % mod;
			}
		}

		if (operatorAtK == '^') {
			if (isTrue) {
				ans += (falseInLeft * trueInRight) % mod;
				ans += (trueInLeft * falseInRight) % mod;
			} else {
				ans += (falseInLeft * falseInRight) % mod;
				ans += (trueInLeft * trueInRight) % mod;
			}
		}
	}

	return dp[i][j][isTrue] = ans % mod;
}


int Solution::cnttrue(string A) {
	memset(dp, -1, sizeof(dp));
	return booleanParenthesization(A, 0, A.size() - 1, true);
}
