// T - O(N)
// S - O(1)
int minJumps(int nums[], int n) {
	// If we are already at starting index.
	if (n <= 1)
		return 0;

	// Return -1 if not possible
	if (nums[0] == 0)
		return -1;

	// Store the max reach right now
	int maxReach = nums[0];

	// Store the steps that we can take
	int steps = nums[0];

	// Store the jumps required
	int jumps = 1;

	// Traverse the array
	for (int i = 1; i < n; i++) {
		// If we reach the end
		if (i == n - 1)
			return jumps;

		// Update the max reach possible
		maxReach = max(maxReach, i + nums[i]);

		// Account for moving one step head
		steps--;

		// If we don't have any steps
		if (steps == 0) {
			// We must use a jump now
			jumps++;

			// If max reach is smaller or equal than i, then we can't move forward
			if (maxReach <= i)
				return -1;

			// Update steps taking the best value
			steps = maxReach - i;
		}
	}

	return jumps;
}


// ** DP Approach ** //
int minJumpsDP(int nums[], int n) {
	vector<int> jumps(n);

	if (n == 0 or arr[0] == 0)
		return -1;
}