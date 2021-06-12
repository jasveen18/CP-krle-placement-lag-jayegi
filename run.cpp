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
// Rabin Karp is used to match one string to another.
// First calculate the hash of the pattern, now we need to find which
// window of same length of the string matches with the hash of the pattern.

// But calculating hash again and again will give O(N*M), therefore, we will use -
// ROLLING HASH

// String = afbbcde
// Ek first window ka nikal lie value ->

// hashNow = a*p0 + f*p1 + b*p2 + b*p3
// hashNext = f*p0 + b*p1 + b*p2 + c*p3

// So, we are removing a*p0, the first element and then dividing the whole hash by p.

// Now the modulus properties for dividing
// (a / p) % m => a * p^-1 % m

// Fermet's Little Theorem,
// If p is prime, then ->
// a ^ p-1 = 1	(when are modding by p) where p is prime
// a ^ p-2 = a^-1


const long long int mod = 1e9 + 7;
const int primeNum = 31;
// Here, a^b % p, where b is prime. O(Log(b))
long long int powerFunc(long long int a, long long int b) {
	long long int res = 1;

	while (b) {
		if (b & 1ll) {
			res *= a;
			res %= mod;
		}
		b /= 2;
		a *= a;
		a %= mod;
	}

	return res;
}


// Inverse Function
long long int inverseFunc(long long int a) {
	// a^-1 % mod = a^(mod - 2)
	return powerFunc(a, mod - 2);
}


// Hash Function
long long int polyHashString(string s) {
	long long int hashValue = 0;
	long long int powerNow = 1;
	long long int n = s.size();

	// Hash function
	for (int i = 0; i < n; i++) {
		hashValue += (powerNow * (s[i] - 'a' + 1));
		powerNow *= primeNum;
		powerNow %= mod;
		hashValue %= mod;
	}

	return hashValue % mod;
}


void rabinKarpAlgo(string text, string pattern) {
	long long int n = text.size(), m = pattern.size();
	long long int patternHash = polyHashString(pattern);

	vector<long long int> pref(n);
	for (int i = 0; i < n; i++) {
		pref[i] = (text[i] - 'a' + 1) * powerFunc(primeNum, i);
		pref[i] %= mod;
	}

	for (int i = 1; i < n; i++) {
		pref[i] += pref[i - 1];
		pref[i] %= mod;
	}

	for (int i = 0; i + m <= n; i++) {
		// Substring from s[l...r]
		// r = i + m - 1

		int newHash = pref[i + m - 1];
		if (i - 1 >= 0)
			newHash -= pref[i - 1];
		newHash += mod; newHash %= mod;

		if (newHash == (patternHash * powerFunc(primeNum, i)) % mod)
			cout << i << endl;
	}
}


int main() {
	blink
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	rabinKarpAlgo("abbabs", "ab");
	// cout << powerFunc(4, 2);

	return 0;
}