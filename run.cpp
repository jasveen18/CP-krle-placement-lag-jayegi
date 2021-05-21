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


class Solution {
public:
	vector<long long> mergeSort(vector<long long> arr, long long start, long long end, long long int &count) {
		// If there is any element to sort
		if (start < end) {
			int mid = (start + end) / 2;

			// Recursive calls
			vector<long long> left = mergeSort(arr, start, mid, count);
			vector<long long> right = mergeSort(arr, mid + 1, end, count);

			// Merge operation
			int i = 0, j = 0, k = 0;
			while (i < left.size() and j < right.size()) {
				if (left[i] > right[j]) {
					count++;
					cout << left[i] << " " << right[j] << endl;

					arr[k++] = right[j++];
				} else {
					arr[k++] = left[i++];
				}
			}

			while (i < left.size())
				arr[k++] = left[i++];
			while (j < right.size())
				arr[k++] = right[j++];
		}

		return arr;
	}


	// arr[]: Input Array
	// N : Size of the Array arr[]
	// Function to count inversions in the array.
	long long int inversionCount(long long arr[], long long N)
	{
		long long int countInversions = 0;
		vector<long long> myarr(arr, arr + N);

		mergeSort(myarr, 0, N - 1, countInversions);
		return countInversions;
	}

};


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
		Solution obj;
		cout << obj.inversionCount(A, N) << endl;
	}

	return 0;
}

