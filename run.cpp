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

void dfsTimeIt(int src, vector<int> adjList[], vector<bool> &vis, int &timer, vector<int> &startTime, vector<int> &endTime) {
	vis[src] = true;
	startTime[src] = timer++;

	for (auto nbr : adjList[src]) {
		if (vis[nbr] == false) {
			dfsTimeIt(nbr, adjList, vis, timer, startTime, endTime);
		}
	}

	endTime[src] = timer++;
}


void isPossibleToFind(int n, vector<pair<int, int>> &edgeList, int q, vector<vector<int>> &queries) {
	// Convert edge list to adj list
	vector<int> adjList[n];
	for (int i = 0; i < edgeList.size(); i++) {
		adjList[edgeList[i].first].push_back(edgeList[i].second);
	}

	vector<bool> vis(n, false);
	vector<int> startTime(n, 0);
	vector<int> endTime(n, 0);
	int timer = 0;

	// Store the start time and end time of the nodes
	dfsTimeIt(0, adjList, vis, timer, startTime, endTime);

	for (int i = 0; i < queries.size(); i++) {
		int dir = queries[i][0], dest = queries[i][1], src = queries[i][2];

		if (dir == 0) {
			if (startTime[src] > startTime[dest] and endTime[src] < endTime[dest])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		} else {
			if (startTime[dest] > startTime[src] and endTime[dest] < endTime[src])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	// cout<<"Test"<<endl;
	return;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<pair<int, int>> edgeList;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		edgeList.push_back({u - 1, v - 1});
	}
	int q; cin >> q;
	vector<vector<int>> queries;
	for (int i = 0; i < q; i++) {
		int a, b, c; cin >> a >> b >> c;
		queries.push_back({a, b - 1, c - 1});
	}

	isPossibleToFind(n, edgeList, q, queries);

	return 0;
}