int squareRoot(int n, int precision) {
	int s = 0;
	int e = n;
	int ans = -1;

	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (mid * mid <= n) {
			ans = mid;
			s = mid + 1;
		}
		if (mid * mid > e)
			e = mid - 1;
	}

	// Floating part by using Brute Force.
	float inc = 0.1;
	for (int times = 1; times <= precision; times++) {
		while (ans * ans <= n) {
			ans = ans + inc;
		}

		// Overshort the value
		ans = ans - inc;
		inc = inc / 10;
	}

	return ans;
}