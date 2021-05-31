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

void wordBreakCompute(string &s, int idx, unordered_map<string, int> &isPresent,
                      string currWord, vector<string> cache, vector<string> &res) {

	// Base Case
	if (idx == s.size()) {
		if (isPresent.find(currWord) != isPresent.end()) {
			cache.push_back(currWord);

			string temp = "";
			for (int i = 0; i < cache.size() - 1; i++) {
				temp += cache[i] + " ";
			}
			temp += cache[cache.size() - 1];

			res.push_back(temp);
			return;
		} else
			return;
	}

	// Recusive Case
	// Word present
	if (isPresent.find(currWord) != isPresent.end()) {
		// Include it
		wordBreakCompute(s, idx + 1, isPresent, currWord + s[idx], cache, res);

		// Exclude it
		cache.push_back(currWord);
		wordBreakCompute(s, idx, isPresent, "", cache, res);
	} else {
		wordBreakCompute(s, idx + 1, isPresent, currWord + s[idx], cache, res);
	}

	return;
}


vector<string> wordBreak(int n, vector<string>& dict, string s) {
	string currWord = "";
	vector<string> res;
	vector<string> cache;

	unordered_map<string, int> isPresent;
	for (int i = 0; i < n; i++)
		isPresent[dict[i]]++;

	wordBreakCompute(s, 0, isPresent, currWord, cache, res);
	return res;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "catsandog";
	vector<string> dict{"cats", "cat", "and", "sand", "dog"};

	wordBreak(5, dict, s);
}