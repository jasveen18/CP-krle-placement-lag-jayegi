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


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	TestCase {
		int n, c; cin >> n >> c;
		vector<int> stalls(n);
		for (int i = 0; i < n; i++)
			cin >> stalls[i];

		cout << aggresiveCows(n, c, stalls) << endl;
	}

	return 0;
}

