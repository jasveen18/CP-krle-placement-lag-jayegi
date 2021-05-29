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


void printKthPermutation(int n ) {
	string oneToN = "";
	for (int i = 1; i <= n; i++) {
		oneToN += (i + '0');
	}

	vector<string> res;
	generatePermutations(oneToN, 0, res);
	sort(res.begin(), res.end());

	return res[k + 1];
}
