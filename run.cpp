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

bool generateAllPaths(vector<vector<int>> &m, int i, int j, string currPath, vector<string> &paths) {
	if (i == m.size() - 1 and j == m[0].size() - 1) {
		currPath += to_string(m[i][j]);
		paths.push_back(currPath);
		return false;
	}

	// Out of bound case
	if (i < 0 or j < 0 or i >= m.size() or j >= m[0].size())
		return false;

	bool down = printAllPaths(m, i + 1, j, currPath + to_string(m[i][j]), paths);
	bool right = printAllPaths(m, i, j + 1, currPath + to_string(m[i][j]), paths);

	return down or right;
}

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int> (n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	string res = "";
	vector<string> r;
	printAllPaths(m, 0, 0, res, r);
}

