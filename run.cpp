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

vector<int> findSum(int root, vector<vector<int>> &adjList, vector<int> nodes, int &res) {
	// Invalid node
	if (root >= nodes.size()) {
		return {0};
	}

	// check for leaf
	if (adjList[root].size() == 0)
		return {nodes[root]};

	vector<vector<int>> prodHere;
	for (auto child : adjList[root]) {
		vector<int> childProd = findSum(child, adjList, nodes, res);
		prodHere.push_back(childProd);
	}

	vector<int> flatten;
	for (auto a : prodHere) {
		for (auto b : a) {
			flatten.push_back(nodes[root] * b);
		}
	}

	for (int i = 0; i < flatten.size(); i++) {
		for (int j = i + 1; j < flatten.size(); j++) {
			res = max(res, flatten[i] * flatten[j]);
		}
	}

	return flatten;
}

int solve(vector<int> nodes, vector<vector<int>> edges) {
	int n = nodes.size();

	// make the adj list
	vector<vector<int>> adjList(n);
	for (auto edge : edges) {
		adjList[edge[0] - 1].push_back(edge[1] - 1);
	}

	// recursive function to find max product
	int res = INT_MIN;
	findSum(0, adjList, nodes, res);

	return res;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int size;
	cin >> size;
	vector<int> nodes(size);

	for (int i = 0; i < size; i++)
		cin >> nodes[i];

	int numedges, col; cin >> numedges >> col;
	vector<vector<int>> edges;

	for (int i = 0; i < numedges; i++) {
		int u, v; cin >> u >> v;
		edges.push_back({u, v});
	}

	cout << solve(nodes, edges);

	return 0;
}