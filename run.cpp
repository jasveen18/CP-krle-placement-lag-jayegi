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

string divBy2(string s) {
	int n = s.size();
	int i = 0;
	string res = "";
	int carry = 0;

	while (i < n) {
		if ((s[i] - '0') < 2) {
			if (i == n - 1)
				return "3"; // Odd number

			res += (((s[i] - '0') * 10 + s[i + 1] - '0') / 2) + '0';
			carry = (((s[i] - '0') * 10 + s[i + 1] - '0') % 2);

			if (!carry)
				i += 2;
			else {
				i++;
				s[i] = carry + '0';
			}
		} else {
			res += ((s[i] - '0') / 2) + '0';
			carry = ((s[i] - '0') % 2);

			if (!carry)
				i++;
			else
				s[i] = carry + '0';
		}

		// deb(s);
	}

	// Remove zeroes at the beginning
	int idx = 0;
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != '0') {
			idx = i;
			break;
		}
	}

	return res.substr(idx);
}


int Solution::power(string A) {

	if (A == “2”) return 1;

	int n = A.length();

	if ((A[n - 1] - ‘0’) % 2 == 1) return 0;

	int carry = 0;

	string ans = "";

	bool b = true;

	for (int i = 0; i < n; i++) {

		int a = A[i] - ‘0’;

		a += carry * 10;

		carry = a % 2;

		a /= 2;

		if (!b || a != 0) {

			ans += a + ‘0’;

			b = false;

		}

	}

	return power(ans);

}



int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << power("147573952589676412928") << endl;
	// cout << (('1' - '0') * 10 + ('6' - '0')) / 2;

	return 0;
}