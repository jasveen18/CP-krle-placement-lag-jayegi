/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 2. 944. Delete Columns to Make Sorted
int minDeletionSize(vector<string>& strs) {
	int res = 0;

	for (int i = 0; i < strs[0].size(); i++) {

		for (int j = 0; j < strs.size() - 1; j++) {
			if (strs[j][i] > strs[j + 1][i]) {
				res++;
				break;
			}
		}
	}

	return res;
}


// 3. 942. DI String Match
vector<int> diStringMatch(string s) {
	int start = 0;
	int end = s.size();

	vector<int> res;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'I') {
			res.push_back(start++);
		} else {
			res.push_back(end--);
		}
	}

	res.push_back(start);
	return res;
}