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


vector<int> parents;

int findSet(int i, int parent[]) {
	if (parent[i] == -1)
		return parent[i] = i;

	return parent[i] = findSet(parent[i], parent);
}


bool unionSet(int x, int y, int parent[], int rank[]) {
	int s1 = findSet(x);
	int s2 = findSet(y);

	if (s1 == s2)
		return true;

	parent[s1] = s2;
	return false;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}


	// No edge
	cout << (n) * (n - 1) / 2 << endl;

	// now make DSU
	parents = vector<int> (n, -1);

	for (int i = m - 1; i >= 0; i--) {
		int u =
	}

	return 0;
}



