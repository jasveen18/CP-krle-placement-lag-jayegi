// Approach - Backtracking
void getPermutations(string s, int idx, set<string> &res) {
	// Base Case
	if (idx == s.size()) {
		res.insert(s);
		return;
	}

	// Recursive Case
	for (int i = idx; i < s.size(); i++) {
		swap(s[i], s[idx]);
		getPermutations(s, idx + 1, res);

		// Backtrack
		swap(s[i], s[idx]);
	}
}