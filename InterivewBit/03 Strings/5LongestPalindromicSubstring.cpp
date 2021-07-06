/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the LPS

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