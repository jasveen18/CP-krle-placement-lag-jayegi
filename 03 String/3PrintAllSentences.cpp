// T - O(N^N)
// S - O(N^N) Recusive Stack
void printAllSentences(vector<vector<string>> data, int idx, string output) {
	// Base Case
	if (idx == data.size()) {
		cout << output << endl;
		return;
	}

	string retainOutputYet = output;
	// Recursive Case
	for (int i = 0; i < data[idx].size(); i++) {
		output += " " + data[idx][i];
		printAllSentences(data, idx + 1, output);
		output = retainOutputYet;
	}

	return;
}