/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print all the sentence you can make.
// 1. You are given n space separated strings, which represents a dictionary of words.
// 2. You are given another string which represents a sentence.
// 3. You have to print all possible sentences from the string, such that words of the sentence are present in dictionary.

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

void wordBreakRec(string s, string ans, unordered_set<string> dict, vector<string> &res) {
	// Base Case
	if (s.size() == 0) {
		// Remove last whitespace
		ans = ans.substr(0, ans.size() - 1);

		res.push_back(ans);
		return;
	}

	// Recursive Case -
	// Try to make every word possible from here
	for (int i = 0; i < s.size(); i++) {
		string word = s.substr(0, i + 1);

		// If we find the word in dict
		if (dict.find(word) != dict.end()) {
			// Then right ke lie search laga do
			string right = s.substr(i + 1);

			wordBreakRec(right, ans + word + " ", dict, res);
		}
	}

	return;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
	unordered_set<string> dict;
	for (int i = 0; i < B.size(); i++)
		dict.insert(B[i]);

	vector<string> res;
	wordBreakRec(A, "", dict, res);

	sort(res.begin(), res.end());

	return res;
}

