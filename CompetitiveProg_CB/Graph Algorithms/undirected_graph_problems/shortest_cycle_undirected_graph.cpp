/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* Ab m game m hu. *
******************************************/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define vin ll n; cin >> n; vector<int> v(n); for (ll i = 0; i < n; i++) cin >> v[i]
#define vout for (ll i = 0; i < n; i++) cout << v[i] << " "
#define ain ll n, k; cin >> n >> k; ll a[n]; for (ll z = 0; z < n; z++) cin >> a[z]
#define TestCase ll t = 1; cin >> t; while (t--)
#define aout for (ll i = 0; i < n; i++) cout << a[i] << " "
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define pb push_back
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

// Breadth First Search
// More like Iterative Way.
// Start with a node and go to all it's neighbors.
// We'll use a queue (like a level order traversal in tree)

// For a unweighted graph, (for weighted we use djisktra)

// Depth First Search
// Recursive Approach
// Goes deep into all the nodes and it's neighbors
// and then return back.

const int N = 100005, M = 22;
vector<int> gr[N];

void bfs(int src, int n, int &ans) {
    vector<int> dist(n + 1, INT_MAX);

    queue<int> Q;
    Q.push(src);
    dist[src] = 0;

    while (Q.empty() == false) {
        int curr = Q.front(); Q.pop();
        for (auto neigh : gr[curr]) {
            if (dist[neigh] == INT_MAX) {
                // Neighbor not visited
                Q.push(neigh);
                dist[neigh] = dist[curr] + 1;
            } else if (dist[neigh] >= dist[curr]) {
                // Backedge is encountered
                ans = min(ans, dist[neigh] + dist[curr] + 1);
            }
        }
    }
}


int main()
{
    blink
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i, j, n, m, ans;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    ans = n + 1;
    for (int i = 1; i <= n; i++) {
        bfs(i, n, ans);
    }

    if (ans == n + 1) {
        cout << "No Cycle" << endl;
    }

    else {
        cout << "Shortest Cycle is of length - " << ans << endl;
    }
}