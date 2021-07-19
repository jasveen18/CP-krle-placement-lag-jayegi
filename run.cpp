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

int sumMinMaxWindowK(vector<int> &nums, int k) {
	int n = nums.size();
	list<int> maxDq, minDq;

	int i = 0, j = 0, ans = 0;

	while (j < n) {
		// Empty the elements smaller than the curr from dq for max
		while (maxDq.empty() == false and maxDq.back() < nums[i])
			maxDq.pop_back();
		maxDq.push_back(nums[i]);

		// Empty the elements larger than the curr from dq for min
		while (minDq.empty() == false and minDq.back() > nums[i])
			minDq.pop_back();
		minDq.push_back(nums[i]);


		if (j - i + 1 < k)
			j++;
		else if (j - i + 1 == k) {
			// Do the calculation
			ans += (maxDq.front() + minDq.front());

			// Slide the window
			if (maxDq.front() == nums[i])
				maxDq.pop_front();
			if (minDq.front() == nums[i])
				minDq.pop_front();

			i++; j++;
		}
	}

	return ans;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << endl << cntBits({1, 3, 5, 6});

	return 0;
}