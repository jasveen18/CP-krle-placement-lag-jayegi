/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min time to complete the order.
bool isPoossibleToCook(vector<int> &ranks, int cooks, int paratas, int time) {
	int paratasCooked = 0;
	for (int i = 0; i < cooks; i++) {
		int p = 0;
		int timeTaken = 0;
		int multiplier = 1;
		while (timeTaken + (ranks[i] * multiplier) < time) {
			p++;
			timeTaken += ranks[i] * multiplier;
			multiplier++;
		}

		paratasCooked += p;
	}

	return paratasCooked >= paratas;
}


int minTimeRequiredToCook(vector<int> &ranks, int cooks, int paratas) {
	// BS use kr lenge in search space.
	int fastestCook = *min_element(ranks.begin(), ranks.end());
	int start = 0, end = INT_MAX;
	int ans = 0;
	// deb2(start, end);

	while (start <= end) {
		int mid = start + (end - start) / 2;

		// is it possible to deliver this much paratas in given time?
		if (isPoossibleToCook(ranks, cooks, paratas, mid)) {
			ans = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ans - 1;
}