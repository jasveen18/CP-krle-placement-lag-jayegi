// Problems involving Linear Recurrences

// f(i) = f(i-1) + f(i-2)
// Here the number of terms (k) is 2. That means it depends on previous 2 terms.
// f(i) = f(i-1) + f(i-2) + f(i-4), here k = 4.

// LR is a function in which the terms are linear combination.
// f(i) = f(i-1) * f(i-2) is not LR.

// ------------------------
// Matrix Exponention - O(k^3 * LogN)
// Steps to solve it.

// 1. Find the value of k
// 2. Find out the first k terms. F1 = [0 1] (first k terms, here 2).
// 3. Find the transformation matrix. It is a k*k (here, 2*2) matrix.
// 3. Tranformation matrix - [0 1
//	   						  1  1] of fibo.
// 4. Fn = T * Fn-1
// 	  Fn = T * (T * Fn-2)
//    Fn = T * (T * (T * Fn-3))
//    Fn = T^n-1 * (F1)

/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* Ab m game m hu. *
******************************************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MODD 1000000000
#define vin ll n; cin >> n; vector<ll> v(n); for (ll i = 0; i < n; i++) cin >> v[i]
#define vout for (ll i = 0; i < n; i++) cout << v[i] << " "
#define TestCase ll t = 1; cin >> t; while (t--)
#define ain ll n, k; cin >> n >> k; ll a[n]; for (ll z = 0; z < n; z++) cin >> a[z]
#define aout for (ll i = 0; i < n; i++) cout << a[i] << " "
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define blink                \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const double PI = 3.141592653589793238463;

/*
__builtin_ffs(x)
  Number of set bits: __builtin_popcount(x)
  Number of leading zeroes: __builtin_clz(x)
  Number of trailing zeroes : __builtin_ctz(x)
  GCD: __gcd(x, y)
*/

/*
Policy Based Data Structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

*/

/*
###################################################
###################################################
*/

// The below code is solution of SEQ from SPOJ.

ll k;
vector<ll> b;
vector<ll> c;

vector<vector<ll>> multiplyMatrix(vector<vector<ll>> A, vector<vector<ll>> B) {
	// Logic to multiply matrices
	vector<vector<ll>> C(k + 1, vector<ll> (k + 1));

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= k; x++) {
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % MODD) % MODD;
			}
		}
	}

	return C;
}


vector<vector<ll>> powMatrix(vector<vector<ll>> &A, ll p) {
	// Base Case
	if (p == 1)
		return A;

	// P is odd
	if (p & 1) {
		return multiplyMatrix(A, powMatrix(A, p - 1));
	}

	vector<vector<ll>> X = powMatrix(A, p / 2);
	return multiplyMatrix(X, X);

}


ll compute(ll n) {

	if (n == 0)
		return 0;

	if (n <= k) {
		return b[n - 1];
	}

	// Indexing from 1, build the first matrix
	vector<ll> F1(k + 1);

	for (int i = 1; i <= k; i++) {
		F1[i] = b[i - 1];
	}

	vector<vector<ll>> transformationMatrix(k + 1, vector<ll> (k + 1));
	for (int i = 1; i <= k - 1; i++) {
		transformationMatrix[i][i + 1] = 1;
	}

	for (int i = 1; i <= k; i++) {
		transformationMatrix[k][i] = c[k - i];
	}

	// 3rd Step
	transformationMatrix = powMatrix(transformationMatrix, n - k);

	// 4th Step - T^n-1 * F1 = Fn
	ll res = 0;
	for (int i = 1; i <= k; i++) {
		res = (res + (transformationMatrix[k][i] * F1[i]) % MODD) % MODD;
	}

	return res;
}


int main()
{
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	TestCase {
		cin >> k;
		ll num;
		ll n;

		for (int i = 0; i < k; i++) {
			cin >> num;
			b.push_back(num);
		}

		for (int i = 0; i < k; i++) {
			cin >> num;
			c.push_back(num);
		}

		cin >> n;
		cout << compute(n) << endl;

		b.clear();
		c.clear();
	}

	return 0;
}