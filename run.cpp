/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
* Ab m game m hu. *
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

void combinationSum(vector<int> &candidates, int target,
                    vector<vector<int>> &res, vector<int> &combination,
                    int begin) {

	// Base Case
	if (!target) {
		res.push_back(combination);
		return;
	}

	for (int i = begin; i<candidates.size() and target >= candidates[i]; i++) {
		combination.push_back(candidates[i]);
		combinationSum(candidates, target - candidates[i], res, combination, i);
		combination.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> res;
	vector<int> combination;

	combinationSum(candidates, target, res, combination, 0);
	return res;
}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;
	vector<int> inp(n);
	for (int i = 0; i < n; i++)
		cin >> inp[i];

	for (int i = 0; i < n; i++) {
		cout << inp[i] << " ";
	}
	cout << endl;

	vector<vector<int>> res = combinationSum(inp, 6);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}