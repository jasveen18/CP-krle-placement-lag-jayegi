// T - O(N*LogN)
// S - O(1)
int countSetBits(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num) {
			ans += (num & 1);
			ans /= 2;
		}
	}

	return ans;
}


// T - O(Log N)
// S - O(1)
int countSetBits(int n) {
	// Add one to compensate for zero.
	n++;

	int powerOf2 = 2;
	int count = n / 2;

	while (powerOf2 <= n) {
		int totalPairs = n / powerOf2;
		count += (totalPairs / 2) * powerOf2;
		count += (totalPairs & 1) ? (n % powerOf2) : 0;

		powerOf2 <<= 1;
	}

	return count;
}