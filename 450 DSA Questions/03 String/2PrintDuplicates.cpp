// T - O(N)
// S - O(1)
void printDuplicates(string s) {
	int n = s.size();
	unordered_map<char, int> countMap;

	// Make the count map
	for (int i = 0; i < n; i++) {
		countMap[s]++;
	}

	// Print the elements
	for (auto el : countMap) {
		if (el.second > 1)
			cout << el.first << " ";
	}
}