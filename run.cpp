/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))

#define TestCase ll t = 1; cin >> t; while (t--)
#define vin ll n; cin >> n; vector<int> v(n); for (ll i = 0; i < n; i++) cin >> v[i]
#define vout for (ll i = 0; i < n; i++) cout << v[i] << " "
#define ain ll n, k; cin >> n >> k; ll a[n]; for (ll z = 0; z < n; z++) cin >> a[z]
#define aout for (ll i = 0; i < n; i++) cout << a[i] << " "

#define blink                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double PI = 3.141592653589793238463;
/********************************/
/**** Your code goes here - ****/
/*******************************/


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

