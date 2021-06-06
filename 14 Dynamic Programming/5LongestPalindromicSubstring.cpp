// *** Longest palindromic substring *** //

// 1. Problem Statement -
// Find the longest palindromic substring.

// 2. Similarity -
// Inp: same as longest palindromic subseq
// Out: same as LPS
// Que: almost same hi hai.

// Mistake -
// In LPS, we reversed the string and passed it into LCS but,
// here if we reverse the string and try to find Longest Common Substring,
// we get wrong answer.

// The case is -
// a => abbcdbba
// rev(a) => abbdcbba
// Here, the answer will be -> abb which is not palindrome.

// Therefore, we need to do modifications in the solution.
// Also, we will look at some other solutions.

// This solution will take around O(N*N*N) time
// O(N*N) space
string longestPalindrome(string s) {
	string y = s;
	reverse(s.begin(), s.end());
	return longestCommonSubstring(s, y, s.size(), s.size());
}

string longestCommonSubstring(string x, string y, int n, int m) {
	// Initialization
	int dp[n + 1][m + 1];
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i <= n; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= m; j++)
		dp[0][j] = 0;

	int lenLongest = -1;
	string longestPalindrome = "";
	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];

				// Check if palindrome or not -
				if (dp[i][j] > lenLongest) {
					string checkThis = x.substr(i - dp[i][j], dp[i][j]);
					string revCheck = checkThis;
					reverse(revCheck.begin(), revCheck.end());

					if (checkThis == revCheck) {
						lenLongest = dp[i][j];
						longestPalindrome = checkThis;
					}
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}

	return longestPalindrome;
}



// Solution 2 - Expand around center.
// We have (2n - 1) centers to pick. Why (2n-1) because, the center can be odd len and even len.
// If we expand towards both sides from each center, we will be able to find the longest substring.
// This runs in O(N*N) and O(1) space

int expandAroundCenter(string s, int left, int right) {
	// Expand around center as far as we can make the palindrome
	while (left >= 0 and right < s.size() and s[left] == s[right]) {
		left--; right++;
	}

	// Return the length of the string we were able to make.
	return right - left - 1;
}


string longestPalindrome(string s) {
	if (s.size() < 0)
		return "";

	int start = 0, end = 0;
	for (int i = 0; i < s.size(); i++) {
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);

		int len = max(len1, len2);

		// Update the start and end index of start and end of string
		// if greater than current length.
		if (len > end - start) {
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}

	string res = "";
	for (int i = start; i <= end; i++)
		res += s[i];
	return res;
}


// Solution 3 - Good DP
// P(i, j) == P(i+1, j-1) && s[i] == s[j];

// Base cases :
//One character
// P(i, i) = true;
//Two character
// P(i, i+1) = s[i] == s[i+1];

// Time Complexity - O(N^2), Space Complexity - O(N^2) (caching all substring)

string longestPalindrome(string s) {
	int n = s.size();
	if (n == 0)
		return "";

	// Initialization
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));

	// For a single length char
	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	string ans = s[0];

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				// If it is a two character string
				// or if it is a valid palindrome
				if (j - i == 1 or dp[i + 1][j - 1]) {
					dp[i][j] = true;

					if (ans.size() < j - i + 1)
						ans = s.substr(i, j - i + 1);
				}
			}
		}
	}

	return ans;
}