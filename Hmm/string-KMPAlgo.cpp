// *** KMP Algorithm *** //

// Problem Statement - To search a substring in a given string.
// string s= "abcbcglx".
// string sub = "bcgl".
// output -> 4

// O(N + M) Time
// O(N) space

bool KMPPatternMatch(string text, string pattern) {
	vector<int> tempPatternArray = computeTempArray(pattern);

	int i = 0, j = 0;
	while (i < text.size() and j < pattern.size()) {
		if (text[i] == pattern[j]) {
			i++; j++;
		}

		else {
			if (j != 0)
				j = tempPatternArray[j - 1];
			else
				i++;
		}
	}

	if (j == pattern.size())
		return true;
	else
		return false;
}


vector<int> computeTempArray(string pattern) {
	vector<int> lps(pattern.size(), 0);
	int len = 0; // len of previous longest prefix suffix

	int i = 1; // lps[i] for i = 1 to M - 1
	while (i < pattern.size()) {
		if (pattern[i] == pattern[len]) {
			lps[i] = ++len;
			i++;
		} else {
			// If len is not zero
			if (len != 0)
				len = lps[len - 1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

	return lps;
}