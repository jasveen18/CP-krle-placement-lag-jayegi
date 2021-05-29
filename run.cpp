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

bool isPossibleEqualPartition(int arr[], int n, int i, int currSum, int totalSum) {
	// Base Cases
	// We can divide the array into 2 parts
	if (currSum == totalSum / 2)
		return true;

	// We can't divide with this configuration
	if (currSum > totalSum / 2)
		return false;

	// Array is exhausted
	if (i == n)
		return false;

	// Recursive Cases
	// Include the current element
	bool includeCase = isPossibleEqualPartition(arr, n, i + 1, currSum + arr[i], totalSum);

	// Exclude the current element
	bool excludeCase = isPossibleEqualPartition(arr, n, i + 1, currSum, totalSum);

	// Is this case a valid config?
	return includeCase or excludeCase;
}


int equalPartition(int N, int arr[]) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
	}

	// If sum is odd
	if (sum & 1)
		return false;

	int currSum = 0;
	return isPossibleEqualPartition(arr, N, 0, currSum, sum);
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << equalPartition(n, arr);
}

