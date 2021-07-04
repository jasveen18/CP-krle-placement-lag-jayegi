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

int findMaxUndefendedBlock(int width, int height, int n, vector<int> &x, vector<int> &y) {
	// Sort the co-ordinates
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	// Find the max difference between any 2 place
	int maxDiffX = x[0] - 1;
	int maxDiffY = y[0] - 1;


	for (int i = 1; i < n; i++) {
		maxDiffX = max(maxDiffX, x[i] - x[i - 1] - 1);
		maxDiffY = max(maxDiffY, y[i] - y[i - 1] - 1);
	}

	// For the last tower, we need to match with end of field
	maxDiffX = max(maxDiffX, width - x[n - 1]);
	maxDiffY = max(maxDiffY, height - y[n - 1]);

	return maxDiffX * maxDiffY;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif



	return 0;
}