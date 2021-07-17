/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/


// 1. 1880. Check if Word Equals Summation of Two Words
int convertToInt(string s) {
	int n = s.size();

	for (int i = 0; i < n; i++) {
		s[i] = s[i] - 'a' + '0';
	}

	return stoi(s);
}

bool isSumEqual(string firstWord, string secondWord, string targetWord) {
	int first = convertToInt(firstWord);
	int second = convertToInt(secondWord);
	int target = convertToInt(targetWord);

	if (first + second == target)
		return true;

	return false;
}


// 2. 1881. Maximum Value after Insertion
string maxValue(string n, int x) {
	bool sign = n[0] == '-';
	int size = n.size();
	string res = "";

	if (sign and n.size() == 1)
		return n;

	int i;

	// If negative that means first greater ke pehle
	if (sign) {
		i = 0; // Skipping the first element ('-')
		while (i < size - 1 and n[i + 1] - '0' <= x)
			i++;
	}

	else { // Else, first smaller ke pehle
		i = -1;
		while (i < size - 1 and n[i + 1] - '0' >= x)
			i++;
	}

	res = n.substr(0, i + 1);
	res += x + '0';
	res += n.substr(i + 1);

	return res;
}