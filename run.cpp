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


void mergeSortCount(long long arr[], long long start, long long end, long long int &count) {
	if (start < end) {
		long long int mid = (start + end) / 2;

		// Recursive function on two halves
		mergeSortCount(arr, start, mid, count);
		mergeSortCount(arr, mid + 1, end, count);

		// Merge Function
		long long i = 0, j = mid + 1, k = 0;
		long long space[end - start + 1];

		while (i <= mid and j <= end) {
			if (arr[i] > arr[j]) {
				count += mid - i + 1;
				space[k++] = arr[j++];
			} else {
				space[k++] = arr[i++];
			}
		}

		// Add the left-over elements
		while (i <= mid) {
			space[k++] = arr[i++];
		}

		while (j <= end) {
			space[k++] = arr[j++];
		}

		for (int x = start; x <= end; x++) {
			arr[x] = space[x];
		}
	}

	return;
}


// Inversion count function to use merge sort to find count inversions
long long int inversionCount(long long arr[], long long N) {
	long long int countInv = 0;
	mergeSortCount(arr, 0, N - 1, countInv);
	return countInv;
}

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long T;
	cin >> T;

	while (T--) {
		long long N;
		cin >> N;

		long long A[N];
		for (long long i = 0; i < N; i++) {
			cin >> A[i];
		}
		cout << inversionCount(A, N) << endl;
	}

	return 0;
}

