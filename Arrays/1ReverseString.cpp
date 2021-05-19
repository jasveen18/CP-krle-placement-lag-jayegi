string reverseWord(string str) {
	for (int i = 0; i < str.length() / 2; i++) {
		swap(str[i], str[str.length() - i - 1]);
	}

	return str;
}