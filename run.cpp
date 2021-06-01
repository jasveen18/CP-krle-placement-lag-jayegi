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

void findCombinations(vector<int> &a, int targetSum, int currSum,
                      vector<int> &runningVec, int idx,
                      vector<vector<int>> &res) {
	//
	if (idx == a.size())
		return;

	// Base Case
	if (currSum == targetSum) {
		res.push_back(runningVec);
		return;
	}

	// Exclude case
	findCombinations(a, targetSum, currSum, runningVec, idx + 1, res);

	// Include case
	runningVec.push_back(a[idx]);
	for (int i = idx; i < a.size(); i++) {
		if (currSum + a[i] <= targetSum) {
			findCombinations(a, targetSum, currSum + a[idx], runningVec, i, res);
		}
	}

	// Backtrack
	runningVec.pop_back();
	return;
}


vector<vector<int>> combinationSum(vector<int> &a, int b) {
	vector<vector<int>> res;
	vector<int> r;
	findCombinations(a, b, 0, r, 0, res);

	// Get unique values and sort according to format
	for (int i = 0; i < res.size(); i++) {
		sort(res[i].begin(), res[i].end());
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

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

	combinationSum(inp, 16);
	return 0;
}