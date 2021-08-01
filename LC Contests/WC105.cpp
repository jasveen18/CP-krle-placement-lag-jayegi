// 1. 917. Reverse Only Letters
string reverseOnlyLetters(string s) {
	string letters = "";
	queue<pair<char, int>> inc;

	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'))
			letters += s[i];
		else
			inc.push({s[i], i});
	}

	reverse(letters.begin(), letters.end());

	string res = "";
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (inc.front().second != i) {
			res += letters[j++];
		} else {
			res += inc.front().first;
			inc.pop();
		}
	}

	return res;
}