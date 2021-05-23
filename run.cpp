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


vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
	vector<int> arr(r * c, 0);
	int i = 0;
	int sc = 0, ec = c - 1, sr = 0, er = r - 1;
	int rowLen = r, colLen = c;

	// Traverse the matrix
	while (sc <= ec and sr <= er) {
		// Left to right
		for (int c = sc; c <= ec; c++) {
			arr[i++] = matrix[sr][c];
		}
		sr++;

		// Top to bottom
		for (int r = sr; r <= er; r++) {
			arr[i++] = matrix[r][ec];
		}
		ec--;

		if (sr <= er) {
			// Right to left
			for (int c = ec; c >= sc; c--) {
				arr[i++] = matrix[er][c];
			}
			er--;
		}

		if (sc <= ec) {
			// Bottom to top
			for (int r = er; r >= sr; r--) {
				arr[i++] = matrix[r][sc];
			}
			sc++;
		}
	}

	return arr;
}

void spiralPrint(vector<vector<int> > arr, int m, int n) {
	int startRow = 0;
	int startCol = 0;
	int endRow = m - 1;
	int endCol = n - 1;

	// Stop conditions
	while (startRow <= endRow and startCol <= endCol) {
		// First Row
		for (int i = startCol; i <= endCol; i++) {
			cout << arr[startRow][i] << " ";
		}
		startRow++;

		// End Column
		for (int i = startRow; i <= endRow; i++) {
			cout << arr[i][endCol] << " ";
		}
		endCol--;

		// Bottom Row
		if (endRow >= startRow) {
			for (int i = endCol; i >= startCol; i--) {
				cout << arr[endRow][i] << " ";
			}
			endRow--;
		}

		// First Column
		if (endCol >= startCol) {
			for (int i = endRow; i >= startRow; i--) {
				cout << arr[i][startCol] << " ";
			}
			startCol++;
		}
	}
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int r, c; cin >> r >> c;
	vector<vector<int> > matrix(r, vector<int> (c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	spiralPrint(matrix, r, c);
	cout << endl;
	vector<int> res = spirallyTraverse(matrix, r, c);
	for (auto num : res) {
		cout << num << " ";
	}
	cout << endl;


	return 0;
}

