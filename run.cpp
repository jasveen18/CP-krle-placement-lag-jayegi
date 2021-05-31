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

bool knightTour(vector<vector<int>> &grid, int i, int j, int blocksFilled) {
	// Base Case
	if (blocksFilled == grid.size() * grid.size())
		return true;

	// Check for invalid cases
	// Out of bound
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid.size())
		return false;

	if (grid[i][j] != -1)
		return false;

	// Recursive Cases
	// We can move at 8 places

	vector<int> movesX{2, 1, -1, -2, -2, -1, 1, 2};
	vector<int> movesY{1, 2, 2, 1, -1, -2, -2, -1};

	// Place the knight here
	grid[i][j] = blocksFilled;
	bool subProbPossible = false;
	for (int k = 0; k < 8; k++) {
		subProbPossible = knightTour(grid, i + movesX[k],
		                             j + movesY[k], blocksFilled + 1);

		if (subProbPossible)
			return true;
	}

	// Backtracking
	grid[i][j] = -1;
	return false;
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 8;
	vector<vector<int>> grid(n, vector<int> (n, -1));

	bool possible = knightTour(grid, 0, 0, 0);

	if (possible) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
}


// 0 59 38 33 30 17 8 63
// 37 34 31 60 9 62 29 16
// 58 1 36 39 32 27 18 7
// 35 48 41 26 61 10 15 28
// 42 57 2 49 40 23 6 19
// 47 50 45 54 25 20 11 14
// 56 43 52 3 22 13 24 5
// 51 46 55 44 53 4 21 12