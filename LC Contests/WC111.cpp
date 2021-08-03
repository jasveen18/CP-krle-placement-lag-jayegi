/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. Valid Mountain Array
bool validMountainArray(vector<int>& A) {
	// 2 people climbing from both sides, must meet in the middle
	int n = A.size(), i = 0, j = n - 1;

	while (i + 1 < n && A[i] < A[i + 1])
		i++;
	while (j > 0 && A[j - 1] > A[j])
		j--;

	return i > 0 && i == j && j < n - 1;
}

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