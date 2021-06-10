char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void generate_names(char *in, char *out, int i, int j) {

	// Base Case
	if (in[i] == '\0') {
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// Recursive Case
	int digit = in[i] - '0';
	if (digit == 1 || digit == 0)
		generate_names(in, out, i + 1, j);

	for (int k = 0; k < strlen(keypad[digit]); k++) {
		out[j] = keypad[digit][k];
		generate_names(in, out, i + 1, j + 1);
	}
}