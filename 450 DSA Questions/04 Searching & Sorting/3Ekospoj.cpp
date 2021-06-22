/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Fulfill the required woods, but take the least amount of wood.
bool isPossibleToFill(vector<ll> &heights, ll n, ll requiredWood, ll cutHeight) {
	ll woodObtained = 0;

	for (ll i = 0; i < n; i++) {
		woodObtained += max((ll)0, heights[i] - cutHeight);
	}

	return woodObtained >= requiredWood;
}


ll ecoCuts(vector<ll> &heights, ll n, ll requiredWood) {
	// We will use BS on the search space.
	ll low = 0, high = *max_element(heights.begin(), heights.end());
	ll ans = low;

	while (low <= high) {
		ll mid = low + (high - low) / 2;

		if (isPossibleToFill(heights, n, requiredWood, mid)) {
			ans = mid;
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return ans;
}