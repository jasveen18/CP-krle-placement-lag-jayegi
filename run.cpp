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


int editDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();

	vector<vector<int>> distanceDP(m + 1, vector<int> (n + 1, 0));
	for (int i = 1; i <= m; i++)
		distanceDP[i][0] = i;
	for (int j = 1; j <= n; j++)
		distanceDP[0][j] = j;

	// DP logic
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1]) {
				distanceDP[i][j] = distanceDP[i - 1][j - 1];
			} else {
				distanceDP[i][j] = 1 + min3(distanceDP[i - 1][j - 1], distanceDP[i][j - 1], distanceDP[i - 1][j]);
			}
		}
	}

	return distanceDP[m][n];
}

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s, t;
	cin >> s >> t;

	cout << editDistance(s, t);


	return 0;
}

