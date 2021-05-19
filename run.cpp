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


// Approach 1 - Using 2 pointers
// Time Complexity - O(N)
// Space Complexity - O(1)
void moveNegNumToStart(vector<int> &nums) {
	int n = nums.size();

	int low = 0, high = n - 1;
	while (low < high) {
		while (nums[low] < 0 and low < high)
			low++;

		while (nums[high] >= 0 and low < high)
			high--;

		if (nums[low] > 0 and nums[high] >= 0) {
			swap(nums[low], nums[high]);
			low++, high--;
		}
	}
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> nums {10, 23, -43, -123, 11};

	for (auto n : nums) {
		cout << n << " ";
	}
	cout << endl;

	moveNegNumToStart(nums);

	for (auto n : nums) {
		cout << n << " ";
	}
	cout << endl;
}