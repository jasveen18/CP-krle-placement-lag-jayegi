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
#define debvec(x) for (int i=0; i<x.size(); i++) cout<< x[i] << " "
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

int solve(vector<vector<int> > &dp) {
	int res = 0;
	int n = dp.size(), m = dp[0].size();

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = min(min(dp[i][j], dp[i - 1][j - 1]), min(dp[i][j - 1], dp[i - 1][j])) + 1;
			res = max(res, dp[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return res * res;
}

int evalRPN(vector<string> A) {
	stack<int> st;
	int res = 0;

	for (int i = 0; i < A.size(); i++) {
		if ((A[i][0] == '+' or A[i][0] == '-' or A[i][0] == '*' or A[i][0] == '/') and A[i].size() == 1) {
			int first = st.top(); st.pop();
			int second = st.top(); st.pop();
			int res;
			if (A[i][0] == '+')
				res = second + first;
			if (A[i][0] == '-')
				res = second - first;
			if (A[i][0] == '*')
				res = second * first;
			if (A[i][0] == '/')
				res = second / first;

			st.push(res);
		} else {
			st.push(stoi(A[i]));
		}
	}

	return st.top();
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << evalRPN({"-1"});
	return 0;
}