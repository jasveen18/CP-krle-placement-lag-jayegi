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