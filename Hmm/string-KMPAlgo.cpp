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
	while (i < tex.size() and j < pattern.size()) {
		if (tex[i] == pattern[j]) {
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
	vector<int> res(pattern.size(), 0);
	int idx = 0;

	for (int i = 1; i < pattern.size();) {
		if (pattern[i] == pattern[idx]) {
			res[i] = idx + 1;
			idx++;
			i++;
		}
	} else {
		if (idx != 0) {
			idx = res[idx - 1];
		} else {
			res[idx] = 0;
			i++;
		}
	}

	return res;
}