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


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n, requiredWood;
	cin >> n >> requiredWood;

	vector<ll> heights(n);
	for (ll i = 0; i < n; i++)
		cin >> heights[i];

	cout << ecoCuts(heights, n, requiredWood);

	return 0;
}

