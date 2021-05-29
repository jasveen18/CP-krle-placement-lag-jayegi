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

	// getAllCombinatinSums(A, B, currSum, currVec, res, 0);

	// Do the computations
	set<vector<int>> result(res.begin(), res.end());
	vector<vector<int>> finalRes(result.begin(), result.end());

	for (int i = 0; i < finalRes.size(); i++) {
		sort(finalRes[i].begin(), finalRes[i].end());
	}

	sort(finalRes.begin(), finalRes.end());
	return finalRes;
}



bool isSafeForQueen(vector<vector<int>> &board, int i, int j) {
	// Check the column. Row pe toh ni hoga.
	for (int row = 0; row < i; row++) {
		if (board[row][j])
			return false;
	}

	// Check for left diagonal
	int x = i;
	int y = j;
	while (x >= 0 and y >= 0) {
		if (board[x][y])
			return false;

		x--; y--;
	}

	// Check for right diagonal
	x = i;
	y = j;
	while (x >= 0 and y < board.size()) {
		if (board[x][y])
			return false;

		x--; y++;
	}


	return true; // If all conditions don't match.
}



bool printAllNQueens(int n, vector<vector<int>> &board, int i) {
	// Base Case when we have arranged the board
	if (i == n) {

		// Print the board
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1)
					cout << "Q";
				else
					cout << ".";
			}
			cout << endl;
		}
		cout << endl;

		return false; // To find further configurations
	}

	// Recursive Case
	for (int j = 0; j < n; j++) {
		// Place queen at i, j if it is safe.
		if (isSafeForQueen(board, i, j)) {
			board[i][j] = 1;

			// Run further
			bool nextQueensRakhPaaye = printAllNQueens(n, board, i + 1);
			if (nextQueensRakhPaaye)
				return true;

			// If not, backtrack
			board[i][j] = 0;
		}
	}

	// We couldn't place the queen here because of our previous configs
	return false;
}


void driverPrintQueens(int n) {
	vector<vector<int>> board(n, vector<int>(n));

	// Arrange the board and print when final config
	printAllNQueens(n, board, 0);
	return;
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	// int n;
	// cin >> n;
	// vector<int> arr(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> arr[i];
	// }
	// int a; cin >> a;

	// vector<vector<int>> res = combinationSum(arr, a);
	// for (int i = 0; i < res.size(); i++) {
	// 	for (int j = 0; j < res[i].size(); j++) {
	// 		cout << res[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	driverPrintQueens(4);
}

