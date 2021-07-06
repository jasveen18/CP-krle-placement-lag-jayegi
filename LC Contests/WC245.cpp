/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 1897. Redistribute Characters to Make All Strings Equal
bool makeEqual(vector<string>& words) {
	unordered_map<char, int> count;
	int n = words.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < words[i].size(); j++)
			count[words[i][j]]++;
	}

	for (auto el : count) {
		if (el.second % n != 0)
			return false;
	}

	return true;
}


// 2. 1898. Maximum Number of Removable Characters
