/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return true or false
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