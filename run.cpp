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

int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
	int dp[n1 + 1][n2 + 1][n3 + 3];
	memset(dp, 0, sizeof(dp));

	// Build up the dp
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			for (int k = 1; k <= n3; k++) {
				if (A[i - 1] == B[j - 1] and A[i - 1] == C[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1];
				} else {
					vector<int> check{dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]};
					dp[i][j][k] = *max_element(check.begin(), check.end());
				}
			}
		}
	}

	return dp[n1][n2][n3];
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << printLCS("abcdef", "adsdfgsdfgdsfgf", 6, 15);

	return 0;
}