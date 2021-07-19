/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print all the sentence you can make.
// 1. You are given n space separated strings, which represents a dictionary of words.
// 2. You are given another string which represents a sentence.
// 3. You have to return the count / true / false that whether you can break or not

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: true


// DP ka meaning kya hoga ki ith index tk ke string pe kitne valid sentences ban skte hai.

bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> dict;

	for (int i = 0; i < wordDict.size(); i++)
		dict.insert(wordDict[i]);

	// Suffix check krenge, agar suffix present hai in dictionary toh usko break krenge.
	// Phir dp pe jump kro piche uss word.len() minus krke waha ke answer ko add kr do.
	vector<int> dp(s.size() + 1, 0);

	for (int i = 0; i < s.size(); i++) {
		// Suffix loop
		for (int j = 0; j <= i; j++) {
			string word2Check = s.substr(j, i - j + 1);

			// Check if present or not
			if (dict.find(word2Check) != dict.end()) {
				if (j > 0)
					dp[i] += dp[j - 1] % mod;
				else // For the first word
					dp[i] += 1;
			}
		}
	}

	// dp[n] pe count of sentences rakha hai.
	return dp[s.size() - 1] > 0;
}


// Interview Bit ka solution ->
int Solution::wordBreak(string A, vector<string> &B) {
	int n = A.size();

	unordered_set<string> dict;

	for (int i = 0; i < B.size(); i++)
		dict.insert(B[i]);

	vector<int> dp(n + 1, 0);
	dp[n] = 1;

	for (int i = n - 1; i >= 0; i--) {

		for (int j = i; j < n; j++) {
			string s = A.substr(i, j - i + 1);

			if (dict.find(s) != dict.end() && dp[j + 1] == 1) {
				dp[i] = 1;
				break;
			}
		}

	}

	return dp[0];
}