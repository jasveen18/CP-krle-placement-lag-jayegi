/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 953. Verifying an Alien Dictionary
bool isAlienSorted(vector<string>& words, string order) {
	unordered_map<char, int> ordering;
	for (int i = 0; i < order.size(); i++)
		ordering[order[i]] = i;


	vector<string> sorting(words.begin(), words.end());

	sort(sorting.begin(), sorting.end(), [&](string a, string b) {
		int size = min(a.size(), b.size());
		for (int x = 0; x < size; x++) {
			if (a[x] == b[x])
				continue;
			return ordering[a[x]] < ordering[b[x]];
		}

		return a.size() < b.size();
	});

	for (int i = 0; i < words.size(); i++) {
		if (words[i] != sorting[i])
			return false;
	}

	return true;
}