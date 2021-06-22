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


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	TestCase {
		int paratas, cooks;
		cin >> paratas >> cooks;
		vector<int> ranks(cooks);

		for (int i = 0; i < cooks; i++)
			cin >> ranks[i];

		cout << minTimeRequiredToCook(ranks, cooks, paratas) << endl;
	}

	return 0;
}

