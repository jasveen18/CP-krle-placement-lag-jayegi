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


bool doKPartitions(int a[], int n, int currSum, int targetSum,
                   vector<int> &visited,  int k, int nextIdx) {
	// Base Case - we were able to fit all the cases
	if (k == 0)
		return true;

	// Base Case - if curr sum is equal to target, then we found a group
	if (currSum == targetSum) {
		return doKPartitions(a, n, 0, targetSum, visited, k - 1, 0);
	}

	// Recursive Case
	for (int i = nextIdx; i < n; i++) {
		if (!visited[i] && currSum + a[i] <= targetSum) {
			visited[i] = 1;
			bool canWeDoSubprob = doKPartitions(a, n, currSum + a[i], targetSum, visited, k, i + 1);

			if (canWeDoSubprob)
				return true;
		}

		// Backtracking for false case
		visited[i] = 0;
	}

	return false;
}


bool isKPartitionPossible(int a[], int n, int k) {
	vector<int> visited(n, 0);
	int sumOfAllElements = 0;
	int maxNum = -1;

	for (int i = 0; i < n; i++) {
		sumOfAllElements += a[i];
		maxNum = max(maxNum, a[i]);
	}

	// Pruning
	if (sumOfAllElements % k != 0 || maxNum > sumOfAllElements / k)
		return false;

	return doKPartitions(a, n, 0, (sumOfAllElements / k), visited, k, 0);
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << isKPartitionPossible(a, n, 3);
}