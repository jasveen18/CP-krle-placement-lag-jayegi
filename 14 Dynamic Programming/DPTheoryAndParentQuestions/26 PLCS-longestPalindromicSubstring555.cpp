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