void wordBreakCompute(string &s, int idx, unordered_map<string, int> &isPresent,
                      string currWord, vector<string> cache, vector<string> &res) {

	// Base Case
	if (idx == s.size()) {
		if (isPresent.find(currWord) != isPresent.end()) {
			cache.push_back(currWord);

			string temp = "";
			for (int i = 0; i < cache.size() - 1; i++) {
				temp += cache[i] + " ";
			}
			temp += cache[cache.size() - 1];

			res.push_back(temp);
			return;
		} else
			return;
	}

	// Recusive Case
	// Word present
	if (isPresent.find(currWord) != isPresent.end()) {
		// Include it
		wordBreakCompute(s, idx + 1, isPresent, currWord + s[idx], cache, res);

		// Exclude it
		cache.push_back(currWord);
		wordBreakCompute(s, idx, isPresent, "", cache, res);
	} else {
		wordBreakCompute(s, idx + 1, isPresent, currWord + s[idx], cache, res);
	}

	return;
}


vector<string> wordBreak(int n, vector<string>& dict, string s) {
	string currWord = "";
	vector<string> res;
	vector<string> cache;

	unordered_map<string, int> isPresent;
	for (int i = 0; i < n; i++)
		isPresent[dict[i]]++;

	wordBreakCompute(s, 0, isPresent, currWord, cache, res);
	return res;
}