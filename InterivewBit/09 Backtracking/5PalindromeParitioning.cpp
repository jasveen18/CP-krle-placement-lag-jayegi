/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -Given a string s, partition s such that every string of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",

// Return

//   [
//     ["a","a","b"]
//     ["aa","b"],
//   ]
bool isPalindrome(string s, int i, int j) {
	if (i == j)
		return true;
	if (i > j)
		return true;

	while (i < j) {
		if (s[i] == s[j]) {
			i++; j--;
		} else {
			return false;
		}
	}

	return true;
}

void dfsTraversal(string s, int i, vector<string> &path, vector<vector<string>> &res) {
	if (i == s.size()) {
		res.push_back(path);
		return;
	}

	for (int x = i; x < s.size(); x++) {
		if (isPalindrome(s, i, x)) {
			path.push_back(s.substr(i, x - i + 1)); // Push the palindrome
			// Search from next element
			dfsTraversal(s, x + 1, path, res);

			// Backtrack
			path.pop_back();
		}
	}

	return;
}

bool myComp(vector<string> &a, vector<string> &b) {
	for (int i = 0; i < min(a.size(), b.size()); i++) {
		if (a[i].size() != b[i].size())
			return a[i].size() < b[i].size();
	}

	return a.size() < b.size();
}

vector<vector<string> > Solution::partition(string A) {
	vector<vector<string>> res;
	if (A.empty()) return res;

	vector<string> path;
	dfsTraversal(A, 0, path, res);

	sort(res.begin(), res.end(), myComp);
	return res;
}
