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

int maxSumTraversing(vector<int> &arr1, vector<int> &arr2, int n, int m) {
	int ans = 0;
	int runningSum1 = 0, runningSum2 = 0;
	int p1 = 0, p2 = 0;

	while (p1 < n and p2 < m) {
		if (arr1[p1] == arr2[p2]) {
			// Add to answer
			ans += max(runningSum1, runningSum2) + arr1[p1];

			// Reset back
			p1++; p2++;
			runningSum1 = 0;
			runningSum2 = 0;
		} else if (arr1[p1] < arr2[p2]) {
			runningSum1 += arr1[p1++];
		} else {
			runningSum2 += arr2[p2++];
		}
	}

	while (p1 < n) {
		runningSum1 += arr1[p1++];
	}

	while (p2 < m) {
		runningSum2 += arr2[p2++];
	}

	return ans + max(runningSum1, runningSum2);
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	while (n != 0) {
		vector<int> seq1(n);
		for (int i = 0; i < n; i++)
			cin >> seq1[i];

		int m; cin >> m;
		vector<int> seq2(m);
		for (int i = 0; i < m; i++)
			cin >> seq2[i];


		cout << maxSumTraversing(seq1, seq2, n, m) << endl;
		cin >> n;
	}

	return 0;
}

