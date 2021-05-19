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

// Approach 2 - Tournament Method (Divide and Conquer)
// [minNum, maxNum]
vector<int> minMaxListDnC(vector<int> nums, int low, int high) {
	// Base Case - if n = 1, both min and max will be first element
	if (low == high)
		return {nums[low], nums[low]};

	// If n = 2, return answer in one comparison
	if (high - 1 == low)
		return {min(nums[low], nums[high]), max(nums[low], nums[high])};

	// Recursive Case
	int mid = (low + high) / 2;
	vector<int> resLeft = minMaxListDnC(nums, low, mid);
	vector<int> resRight = minMaxListDnC(nums, mid + 1, high);
	vector<int> resHere = {nums[low], nums[low]};

	// Min and Max of current level
	resHere[0] = min3(resHere[0], resLeft[0], resRight[0]);
	resHere[1] = max3(resHere[1], resLeft[1], resRight[1]);

	return resHere;
}

int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> nums {10, 23, 43, 123, 11};
	vector<int> res = minMaxListDnC(nums, 0, 4);
	cout << res[0] << " " << res[1];
}