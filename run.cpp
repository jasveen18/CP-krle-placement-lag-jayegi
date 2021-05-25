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


string generateKeypadSequences(string s) {
	string str[] = {"2", "22", "222",
	                "3", "33", "333",
	                "4", "44", "444",
	                "5", "55", "555",
	                "6", "66", "666",
	                "7", "77", "777", "7777",
	                "8", "88", "888",
	                "9", "99", "999", "9999"
	               };

	string resKeypad = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			resKeypad += '0';
		else {
			int position = s[i] - 'A';
			resKeypad += str[position];
		}
	}

	return resKeypad;
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	string s = "HELLO WORLD";

	cout << generateKeypadSequences(s);
	return 0;
}

