int Solution::isPalindrome(int A) {
	if (A < 0)
		return 0;

	long long int dummy = A;
	long long int n = A;

	long long int start = 1;
	long long int end = 10;
	int i = 0, j = 0;


	// Count the power of 10 required
	while (dummy) {
		j++;
		start *= 10;
		dummy /= 10;
	}
	start /= 10;

	long long int startKeLie = n;
	long long int endKeLie = n;

	while (i < j) {
		// Last dig nikal kr /10 krdo for the next last dig.
		int lastDig = endKeLie % 10;
		endKeLie /= 10;

		// First dig nikal kr usko udaa do
		int firstDig = startKeLie / start;
		startKeLie %= start;
		start /= 10;

		if (firstDig != lastDig)
			return 0;
		i++; j--;
	}

	return 1;
}
