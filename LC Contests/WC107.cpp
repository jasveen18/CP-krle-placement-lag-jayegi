// 1. Long Pressed Name
vector<pair<char, int>> getFreqSeq(string s) {
	vector<pair<char, int>> res;

	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];
		int freq = 1;
		while (i < s.size() - 1 and s[i] == s[i + 1]) {
			i++; freq++;
		}

		res.push_back({ch, freq});
	}

	return res;
}

bool isLongPressedName(string name, string typed) {
	vector<pair<char, int>> n = getFreqSeq(name);
	vector<pair<char, int>> t = getFreqSeq(typed);

	if (n.size() != t.size())
		return false;

	for (int i = 0; i < n.size(); i++) {
		if (n[i].first != t[i].first)
			return false;
		if (n[i].second > t[i].second)
			return false;
	}

	return true;
}


// 2. 926. Flip String to Monotone Increasing
int minFlipsMonoIncr(string s) {
	int zero = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '0')
			zero++;


	int res = zero;
	int flip = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			zero--;
		} else {
			flip++;
		}

		res = min(res, zero + flip);
	}

	return res;
}