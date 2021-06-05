/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* Ab m game m hu. *
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


// Recursive Solution -
// nCr(n, 0) = nCr(n, n) = 1;
// nCr(n, r) = nCr(n-1, r-1) + nCr(n-1, r)
long long int binomialCoefficientProblem(int n, int r) {
	const int mod = 1e9 + 7;
	// Initialization
	vector<vector<long long int>> dp(n + 1, vector<long long int> (r + 1, 0));
	for (int j = 0; j <= r; j++)
		dp[0][j] = 0;
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	// Build up the DP
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= r; j++) {
			dp[i][j] = (dp[i - 1][j - 1] % mod) + (dp[i - 1][j] % mod) % mod;
		}
	}

	return dp[n][r] % mod;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << binomialCoefficientProblem(3, 2);

	return 0;
}