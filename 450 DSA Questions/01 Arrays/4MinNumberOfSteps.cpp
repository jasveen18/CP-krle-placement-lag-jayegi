int minJumps(int nums[], int n) {
	int jump = 1;
	int stepNow = nums[0];
	int maxValue = nums[0];

	// Can't reach the end
	if (nums[0] == 0)
		return -1;

	for (int i = 1; i < n; i++) {
		if (i == n - 1) return jump;

		// Take max value of this particular
		maxValue = max(maxValue, i + nums[i]);
		// Move one step ahead
		stepNow--;

		// Take max points possible when steps = 0.
		if (stepNow == 0) {
			jump++;

			// If not possible
			if (i >= maxValue) return -1;

			stepNow = maxValue - i;
		}
	}

	return 0;
}