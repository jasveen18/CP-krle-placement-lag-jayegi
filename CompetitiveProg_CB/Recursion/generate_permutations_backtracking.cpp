void permute(char *in, int i) {
	// Base Case
	if (in[i] == '\0') {
		cout << in << endl;
		return;
	}

	// Recursive Case
	for (int j = i; in[j] != '\0'; j++) {
		swap(in[i], in[j]);
		permute(in, i + 1);

		// Backtrack step - To restore the original array
		swap(in[i], in[j]);
	}

	return;
}