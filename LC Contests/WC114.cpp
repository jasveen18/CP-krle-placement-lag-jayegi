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


// 2.954. Array of Doubled Pairs
bool canReorderDoubled(vector<int>& arr) {
	bool can = true;
	map<int, int> pos;
	map<int, int> neg;

	for (auto el : arr) {
		if (el < 0)
			neg[-el]++;
		else
			pos[el]++;
	}

	if (pos[0] & 1)
		return false;

	pos[0] = 0;
	for (auto el : pos) {
		// cout<<el.first<<" "<<el.second<<endl;
		while (el.second--) {
			int curr = el.first;

			if (pos[curr * 2] == 0)
				return false;

			pos[curr * 2]--;
		}
	}

	for (auto el : neg) {
		// cout<<el.first<<" "<<el.second<<endl;
		while (el.second--) {
			int curr = el.first;

			if (neg[curr * 2] == 0)
				return false;

			neg[curr * 2]--;
		}
	}

	return true;
}


// 3.955. Delete Columns to Make Sorted II
int minDeletionSize(vector<string>& strs) {
	unordered_set<int> idx;

	for (int i = 1; i < strs.size(); i++) {
		for (int k = 0; k < strs[i].size(); k++) {

			// Equal
			if (idx.count(k) != 0 or strs[i - 1][k] == strs[i][k])
				continue;

			if (strs[i - 1][k] > strs[i][k]) {
				idx.insert(k), i = 0; // This row needs to be deleted and we have to search again
			}

			// In instance of greater or smaller we don't need to check ahead
			break;
		}
	}

	return idx.size();
}