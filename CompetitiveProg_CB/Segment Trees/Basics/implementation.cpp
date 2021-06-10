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
#define f(i, n) for(ll i=0; i<n; i++)
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

void buildTree(int arr[], int s, int e, int *tree, int index) {
    // Base Case - The range only has one element.
    if (s == e) {
        tree[index] = arr[s];
        return;
    }

    // Recursive Case
    int mid = s + (e - s) / 2;
    // Left Sub-Tree (Child) - stored at 2*i
    buildTree(arr, s, mid, tree, 2 * index);
    // Right Sub-Tree (Child) - stored at 2*i+1
    buildTree(arr, mid + 1, e, tree, 2 * index + 1);

    // Put the curr element
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}


void segementTree(int arr[], int n, int *tree) {
    // int *tree = new int[4 * n + 1];
    buildTree(arr, 0, n - 1, tree, 1);
}


int performQuery(int *tree, int ss, int se, int qs, int qe, int index) {
    // qs - query start, qe - query end
    // ss - element range start, se - end
    // index - current index
    // tree - already built segment tree.

    // Complete Overlap
    if (ss >= qs and se <= qe)
        return tree[index];

    // No Overlap
    if (qe < ss or qs > se)
        return INT_MAX;

    // Partial Overlap
    int mid = (ss + se) / 2;
    int left = performQuery(tree, ss, mid, qs, qe, 2 * index);
    int right = performQuery(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);
}


int main()
{
    blink
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(arr) / sizeof(int);

    // Data structure to store the tree.
    int *tree = new int[4 * n + 1];

    // Build the segment tree.
    segementTree(arr, n, tree);

    // Print the segment tree.
    for (int i = 1; i <= 13; i++)
        cout << tree[i] << " ";
    cout << endl << endl;

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << q << "--" << endl;
        cout << performQuery(tree, 0, n - 1, l, r, 1) << endl;
    }

    return 0;
}