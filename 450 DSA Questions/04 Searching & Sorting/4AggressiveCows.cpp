/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max distance in the stalls to place cows.


bool isPossibleToPlace(int n, int cows, vector<int> stalls, int dist) {
	// Place the cow at first place
	cows--;
	int lastStallUsed = stalls[0];

	// Now start from 2nd stall and start placing
	for (int i = 1; i < n; i++) {
		if (dist <= stalls[i] - lastStallUsed) {
			cows--;
			lastStallUsed = stalls[i];
		}
	}

	// Return true if we were able to place all the cows
	return cows <= 0;
}

int aggresiveCows(int n, int cows, vector<int> &stalls) {
	int start = 1, end = stalls[n - 1];
	int maxDistance = 1;
	sort(stalls.begin(), stalls.end());

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// Is it possible to place all cows with current space?
		if (isPossibleToPlace(n, cows, stalls, mid)) {
			maxDistance = max(maxDistance, mid);
			start = mid + 1; // If this is achieveable, let's try higher
		} else {
			end = mid - 1;
		}
	}

	return maxDistance;
}