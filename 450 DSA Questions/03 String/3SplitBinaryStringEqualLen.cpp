int splitBinaryStringIntoEqualLen(string s) {
	int n = s.size();
	countZero = 0;
	countOne = 0;
	countSplits = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			countZero++;
		if (s[i] == '1')
			countOne++;

		// when the count is same, we can make a split here
		if (countOne == countZero)
			countSplits++;
	}

	// If it is not possible to split
	if (countZero != countOne)
		return -1;

	return countSplits;
}