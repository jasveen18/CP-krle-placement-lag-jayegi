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

long long int x[40000005], y[40000005];

void createSubArraySum(vector<long long int> &a, long long int x[], long long int n, long long int c) {
	for (long long int i = 0; i < (1 << n); i++) {
		long long int s = 0;
		for (long long int j = 0; j < n; j++)
			if (i & (1 << j))
				s += a[j + c];
		x[i] = s;
	}
}


long long int countSubsetSum(vector<long long int> &arr, long long int n, long long int a, long long int b) {
	// Compute the subset sum of both halves
	createSubArraySum(arr, x, n / 2, 0);
	createSubArraySum(arr, y, n - n / 2, n / 2);

	long long int size_x = 1 << (n / 2);
	long long int size_y = 1 << (n - n / 2);

	// Sort the 2nd array so that we can do binary search on this.
	sort(y, y + size_y);

	long long int ans = 0;

	// Traverse over all the elements of x and do BS to find valid pairs.
	for (long long int i = 0; i < size_x; i++) {
		long long int minSum = a - x[i];
		long long int maxSum = b - x[i];

		long long int upp = upper_bound(y, y + size_y, maxSum) - y;
		long long int low = lower_bound(y, y + size_y, minSum) - y;

		ans += upp - low;
	}

	// if (a <= 0 and b >= 0)
	// 	ans++;

	return ans;
}

int32_t main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int n, a, b; cin >> n >> a >> b;
	vector<long long int> data(n);

	for (long long int i = 0; i < n; i++)
		cin >> data[i];

	cout << countSubsetSum(data, n, a, b);

	return 0;
}

