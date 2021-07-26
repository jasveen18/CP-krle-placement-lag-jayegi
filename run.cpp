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

int longestSubsequenceLength(vector<int> A) {
	// aka Longest Bitonic Subsequence(LBS)
	// create Longest Inc Subseq(LIS) and Longest Dec Subseq(LDS)
	// LBS = max of LIS and LDS - 1
	int N = A.size();
	if (N == 0) return 0;
	vector<int> LIS(N, 1);
	vector<int> LDS(N, 1);

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			//standard LIS condition
			if ((A[i] > A[j]) && (LIS[i] <= LIS[j])) LIS[i] = LIS[j] + 1;
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 1; j > i; j--) {
			//standard LDS condition
			if ((A[i] > A[j]) && (LDS[i] <= LDS[j])) LDS[i] = LDS[j] + 1;
		}
	}

	int max = LIS[0] + LDS[0] - 1;
	for (int i = 1; i < N; i++) {
		if (LIS[i] + LDS[i] - 1 > max)
			max = LIS[i] + LDS[i] - 1;
		deb2(LIS[i], LDS[i]);
	}
	return max;

}

string fractionToDecimal(int A, int B) {
	if (A == INT_MIN and B == -1)
		return "2147483648";
	if (A == 0)
		return "0";

	string ans = "";
	if (A > 0 ^ B > 0)
		ans += '-';

	long n = labs(A), d = labs(d), rem = n % d;
	ans += to_string(n / d);
	if (rem == 0)
		return ans;

	ans += '.';
	unordered_map<long, long> rs;

	while (rem) {
		if (rs.find(rem) != rs.end()) {
			ans.insert(rs[rem], "(");
			ans += ")";
			break;
		}

		rs[rem] = ans.size();
		rem *= 10;
		ans += to_string(rem / d);
		rem %= d;
	}

	return ans;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// cout << longestSubsequenceLength({1, 11, 2, 10, 4, 5, 2, 1});
	cout << fractionToDecimal(-1, -2147483648);

	return 0;
}

