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

bool ratInMaze(vector<vector<int>> &m, int i, int j, string currSeq, vector<string> &res) {
	// Base Case
	if (i == m.size() - 1 and j == m[0].size() - 1) {
		res.push_back(currSeq);
		return false;
	}

	// If rat goes out of grid
	if (i < 0 or j < 0 or i >= m.size() or j >= m[0].size())
		return false;

	// If rat encounters an obstacle
	if (m[i][j] == 0)
		return false;

	// If we are going further in this path, mark as visited
	m[i][j] = 0;
	// cout << i << " " << j << endl;
	bool up = ratInMaze(m, i - 1, j, currSeq + 'U', res);
	bool down = ratInMaze(m, i + 1, j, currSeq + 'D', res);
	bool left = ratInMaze(m, i, j - 1, currSeq + 'L', res);
	bool right = ratInMaze(m, i, j + 1, currSeq + 'R', res);

	// If we find a path
	if (up or down or left or right)
		return true;

	// Backtrack
	m[i][j] = 1;
	return false;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
	string curr = "";
	vector<string> res;

	// for (int i = 0; i < m.size(); i++) {
	// 	for (int j = 0; j < m[0].size(); j++) {
	// 		cout << m[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ratInMaze(m, 0, 0, curr, res);
	return res;
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
	vector<string> result = findPath(m, n);
	if (result.size() == 0)
		cout << -1;
	else
		for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	cout << endl;
}

