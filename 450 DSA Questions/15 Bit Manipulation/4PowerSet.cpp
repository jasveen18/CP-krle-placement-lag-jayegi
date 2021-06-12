// T - O(2^N)
// S - O(N * 2^N)
vector<string> AllPossibleStrings(string s) {
	vector<string> res;
	int n = s.size();
	int countSubsets = pow(2, n);

	for (int i = 1; i < countSubsets; i++) {
		int curr = i;
		int idx = 0;
		string subsetHere = "";
		while (curr) {
			if (curr & 1) {
				subsetHere += s[idx];
			}

			curr /= 2;
			idx++;
		}

		res.push_back(subsetHere);
	}

	sort(res.begin(), res.end());
	return res;
}