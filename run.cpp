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
#define debvec(x) for (int i=0; i<x.size(); i++) cout<< x[i] << " "
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

void dfs(vector<vector<int>> &A, vector<vector<int>> &status, int i, int j, int parent, bool blue) {
	if (A[i][j] < parent)
		return;

	if (status[i][j] >= 1 and blue)
		return;

	if (status[i][j] >= 2)
		return;

	if (blue) {
		if (status[i][j] == 0)
			status[i][j]++;
	}
	else {
		if (status[i][j] == 1)
			status[i][j]++;
		else
			status[i][j] = 10;
	}

	vector<int> delx {0, 0, -1, 1};
	vector<int> dely {1, -1, 0, 0};

	for (int k = 0; k < 4; k++) {
		int x = i + delx[k];
		int y = j + dely[k];

		if (x < 0 or y < 0 or x >= A.size() or y >= A[0].size()) continue;
		else dfs(A, status, x, y, A[i][j], blue);
	}
}

int solve(vector<vector<int> > &A) {
	int n = A.size();
	int m = A[0].size();
	vector<vector<int>> status(n, vector<int>(m, 0)); // 0 -> not visited, 1-> blue water pahuch gya, 2-> red bhi pahuch gya

	// Pehle blue paani pahucha dete hai
	for (int i = 0; i < n; i++) {
		if (status[i][0] == 0)
			dfs(A, status, i, 0, -1, true);
	}
	for (int j = 0; j < m; j++) {
		if (status[0][j] == 0)
			dfs(A, status, 0, j, -1, true);
	}

	// Ab red ko bhara jaaye
	for (int i = 0; i < n; i++) {
		if (status[i][m - 1] == 0 or status[i][m - 1] == 1)
			dfs(A, status, i, m - 1, -1, false);
	}
	for (int j = 0; j < m; j++) {
		if (status[n - 1][j] == 0 or status[n - 1][j] == 1)
			dfs(A, status, n - 1, j, -1, false);
	}


	// Count the nodes
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (status[i][j] == 2)
				res++;
		}
	}

	return res;
}

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> v  {
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4},
	};

	cout << solve(v);
	return 0;
}