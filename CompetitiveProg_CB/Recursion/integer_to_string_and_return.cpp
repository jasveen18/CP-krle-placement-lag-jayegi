// Number to it's spelling
vector<string> spell = {"zero", "one", "two", "three", "four",
                        "five", "six", "seven", "eight", "nine"
                       };

void number_to_spelling(int n) {
	if (n == 0)
		return;

	number_to_spelling(n / 10);
	cout << spell[n % 10] << " ";
}


// String to integer
int string_to_integer(char *a, int n) {
	// Base Case
	if (n == 0)
		return 0;

	int digit = a[n - 1] - '0';
	int small_ans = string_to_integer(a, n - 1);

	return small_ans * 10 + digit;
}