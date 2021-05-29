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


bool isSafe() {

}

bool isValid(int i, int j, vector<vector<int>> grid) {
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
		return false;

	return true;
}


void markUnsafeTiles(vector<vector<int>> &grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			// If we have a landmine here, we will mark the neighboring tiles as unsafe
			if (grid[i][j] == 0) {
				// Up
				if (isValid(i - 1, j, grid))
					grid[i - 1][j] = -1;
				// Down
				if (isValid(i + 1, j, grid))
					grid[i + 1][j] = -1;
				// Left
				if (isValid(i, j - 1, grid))
					grid[i][j - 1] = -1;
				// Right
				if (isValid(i, j + 1, grid))
					grid[i][j + 1] = -1;
			}
		}
	}

	// Now mark all the unsafe areas
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == -1)
				grid[i][j] = 0;
		}
	}

	return;
}


void findShortestPath(vector<vector<int>> &grid, int i, int j, int currDistance, int &minDistance) {
	// Base Case
	if (j == grid[0].size()) {
		minDistance = min(minDistance, currDistance);
		return;
	}

	// Is we encounter the unsafe position
	if (grid[i][j] == 0)
		return;

	// Pruning
	if (currDistance > minDistance)
		return;

	// Recursive Case
	// Mark as visited and then visit in all four directions
	grid[i][j] = 0;
	// Down, Left, Right, Up
	findShortestPath(grid, i + 1, j, currDistance + 1, minDistance);
	findShortestPath(grid, i, j - 1, currDistance + 1, minDistance);
	findShortestPath(grid, i, j + 1, currDistance + 1, minDistance);
	findShortestPath(grid, i - 1, j, currDistance + 1, minDistance);

	// Backtrack
	grid[i][j] = 1;
	return;
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
	vector<vector<int>> res;
	int currSum = 0;
	vector<int> currVec;

	getAllCombinatinSums(A, B, currSum, currVec, res, 0);

	// Do the computations
	set<vector<int>> result(res.begin(), res.end());
	vector<vector<int>> finalRes(result.begin(), result.end());

	for (int i = 0; i < finalRes.size(); i++) {
		sort(finalRes[i].begin(), finalRes[i].end());
	}

	sort(finalRes.begin(), finalRes.end());
	return finalRes;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int a; cin >> a;

	vector<vector<int>> res = combinationSum(arr, a);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

