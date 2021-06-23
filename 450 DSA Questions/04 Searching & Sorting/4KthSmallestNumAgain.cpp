int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	TestCase {
		ll n, q;
		cin >> n >> q;

		vector<pair<ll, ll>> ranges;
		for (ll i = 0; i < n; i++) {
			ll a, b; cin >> a >> b;
			ranges.push_back({a, b});
		}

		sort(ranges.begin(), ranges.end());
		vector<pair<ll, ll>> nonOverLapRanges;

		// Merge the overlapping ranges
		nonOverLapRanges.push_back(ranges[0]);
		for (int i = 1; i < n; i++) {
			if (ranges[i].first <= nonOverLapRanges[i - 1].second)
				nonOverLapRanges[i - 1].second = max(ranges[i].second, nonOverLapRanges[i - 1].second);
			else
				nonOverLapRanges.push_back(ranges[i]);
		}


		// Make a new array to store number of values, prefix array
		vector<ll> numRanges;
		numRanges.push_back(0);
		for (int i = 0; i < nonOverLapRanges.size(); i++) {
			numRanges[i] = nonOverLapRanges[i].second - nonOverLapRanges.first + 1;
		}

		for (int i = 1; i < numRanges.size(); i++) {
			numRanges[i] += numRanges[i - 1];
		}


		while (q--) {
			ll k; cin >> k;

			int idx = binarySearch(numRanges, k);
			if (idx == -1)
				cout << -1 << endl;
			else
				cout << nonOverLapRanges[idx].first - nonOverLapRanges[idx].second + k << endl;

		}
	}

	return 0;
}