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

void getValidParentheses(string s, int idx, int minSkip
                         int leftCount, int rightCount, int skippedCount
                         string currSeq, set<string> validExpressions) {
	// Base Case - End of string
	if (idx == s.size()) {
		if (leftCount == rightCount and skippedCount <= minSkip)
			validExpressions.insert(currSeq);
		skippedCount = min(skippedCount, minSkip);
	}

	// Recursive Case
	// If it is not a bracket
	if (s[idx] != '(' or s[idx] != ')') {
		currSeq += s[idx];
		getValidParentheses(s, idx + 1, minSkip,
		                    leftCount, rightCount, skippedCount,
		                    currSeq, validExpressions);
		currSeq = currSeq.substr(0, currSeq.size() - 1);
	}

	// Left Bracket
	if (s[idx] == '(') {
		getValidParentheses(s, idx + 1, minSkip,
		                    leftCount + 1, rightCount, skippedCount,
		                    currSeq, validExpressions);
	}
}

vector<string> removeInvalidParentheses(string s) {
	set<string> validExpressions;
	string currSeq = "";

	int leftCount = 0, rightCount = 0;

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