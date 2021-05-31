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

bool longestPathWithHurdles(vector<vector<int>> grid, int i, int j, int currRouteLen, int &maxRouteLen) {
	// Base Case
	if (i == grid.size() and j == grid[0].size()) {
		maxRouteLen = max(maxRouteLen, currRouteLen);
		return false;
	}

	// Out of bounds
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
		return false;

	// Hurdles or Re-visit
	if (grid[i][j] == 0)
		return false;

	// Recursive Cases
	grid[i][j] = 0;

	bool d = longestPathWithHurdles(grid, i - 1, j, currRouteLen + 1, maxRouteLen);
	bool l = longestPathWithHurdles(grid, i, j - 1, currRouteLen + 1, maxRouteLen);
	bool u = longestPathWithHurdles(grid, i + 1, j, currRouteLen + 1, maxRouteLen);
	bool r = longestPathWithHurdles(grid, i, j + 1, currRouteLen + 1, maxRouteLen);

	if (d or l or u or r)
		return true;

	// Backtrack
	grid[i][j] = 1;
	return false;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<string> inp{"1234567", "4551711527", "3435335"};
	vector<int> k{4, 3, 3};

	for (int i = 0; i < 3; i++) {
		string maxNum = inp[i];

		findMaximumBacktracking(inp[i], k[i], 0, 0, maxNum);
		cout << maxNum << endl;
	}
}