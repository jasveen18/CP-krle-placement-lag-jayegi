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


// T - O(N)
// S - O(26)
string generateKeypadSequences(string s) {
	string str[] = {"2", "22", "222",
	                "3", "33", "333",
	                "4", "44", "444",
	                "5", "55", "555",
	                "6", "66", "666",
	                "7", "77", "777", "7777",
	                "8", "88", "888",
	                "9", "99", "999", "9999"
	               };

	string resKeypad = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			resKeypad += '0';
		else {
			int position = s[i] - 'A';
			resKeypad += str[position];
		}
	}

	return resKeypad;
}