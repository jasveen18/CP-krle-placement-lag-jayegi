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


bool doKPartitions(int a[], int n, int idx, vector<vector<int>> &nums) {
	// Base Case
	if (idx == n) {
		int sumHere = 0;
		for (int i = 0; i < nums[0].size(); i++)
			sumHere += nums[0][i];

		int prevSum = sumHere;

		bool isPossible = true;
		for (int i = 1; i < nums.size(); i++) {
			sumHere = 0;

			for (int j = 0; j < nums[i].size(); j++) {
				sumHere += nums[i][j];
			}
			if (sumHere != prevSum) {
				isPossible = false;
				break;
			}
		}

		return isPossible;
	}


	// Recursive Case
	// Either to include the current element in our kth basket or not.
	for (int i = 0; i < nums.size(); i++) {
		nums[i].push_back(a[idx]);
		bool isPossibleToFit = doKPartitions(a, n, idx + 1, nums);

		if (isPossibleToFit)
			return true;

		nums[i].pop_back();
	}

	return false;
}


bool isKPartitionPossible(int a[], int n, int k) {
	vector<vector<int>> nums(k);
	// cout << nums.size();

	return doKPartitions(a, n, 0, nums);
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 10;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << isKPartitionPossible(a, n, 2);
}