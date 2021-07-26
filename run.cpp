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



vector<int> solve(vector<int> A, vector<int> B, int C) {
	vector<int> res;
	priority_queue<int> pq;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = A.size() - 1, j = B.size() - 1;

	debvec(A);
	cout << endl;
	debvec(B);

	// pq.push(A[i]); pq.push(B[j]);

	while (res.size() < C) {
		if (i >= 0)
			pq.push(A[i--]);
		if (j >= 0)
			pq.push(B[j--]);

		int one = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();

		res.push_back(one + second);

		if (one > second)
			pq.push(one);
		else
			pq.push(second);
	}


	// sort(res.begin(), res.end(), greater<int>());
	return res;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> res = solve({59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83}, {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83}, 10);
	cout << endl;
	debvec(res);
	return 0;
}

