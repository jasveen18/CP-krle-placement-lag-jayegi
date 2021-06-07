// Approach 1 - Recursion
// T - O(2^N)
// S - O(2^N) Recursive stack
void printSubSeq(string s, string res) {
	// Base Case
	if (s.size() == 0) {
		cout << res << endl;
		return;
	}

	// Recursive Case
	// Include the current element
	printSubSeq(s.substr(1), res + s[0]);

	// Exclude the current element
	printSubSeq(s.substr(1), res);
}


// Approach 2 - Using Bitmask
// T - O(2^N)
// S - O(1)
void printSubSeq(string s) {
	int numOfSubSeq = pow(2, s.size());
	for (int i = 1; i < numOfSubSeq; i++) {
		int idx = 0;
		int num = i;

		// Print the digits which have 1 at its binary representation
		while (num) {
			if (num & 1) {
				cout << s[idx];
			}
			num = num / 2;
			idx++;
		}
		cout << endl;
	}

	return;
}
