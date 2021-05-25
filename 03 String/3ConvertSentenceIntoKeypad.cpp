// T - O(N * 26)
// S - O(26)
string generateKeypadSequences(string s) {
	vector<string> letters{"", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
	string resKeypad = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			resKeypad += '0';
		else {
			for (int j = 0; j < letters.size(); j++) {
				for (int k = 0; k < letters[j].size(); k++) {
					if (s[i] == letters[j][k])
						for (int l = 0; l <= k; l++)
							resKeypad += to_string((j + 1));
				}
			}
		}
	}

	return resKeypad;
}