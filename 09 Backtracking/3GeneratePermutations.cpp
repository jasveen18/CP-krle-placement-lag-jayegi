void generatePermutations(string S, int i, vector<string> &res) {
	// Base Case
	if (i == S.size()) {
		res.push_back(S);
		return;
	}

	// Recursive Case
	for (int j = i; j < S.size(); j++) {
		swap(S[i], S[j]);
		generatePermutations(S, i + 1, res);

		// Backtracking
		swap(S[i], S[j]);
	}

	return;
}

vector<string>find_permutation(string S) {
	vector<string> res;
	generatePermutations(S, 0, res);
	sort(res.begin(), res.end());
	return res;
}