// We will use a prefix sum to match string now.
// Then you can easily hash any substring in O(1) only.

// hash(l, r) =( pref[r] - pref[l-1]) / power(p, l);


const long long int mod = 1e9 + 7;
const int primeNum = 31;
// Here, a^b % p, where b is prime. O(Log(b))
long long int powerFunc(long long int a, long long int b) {
	long long int res = 1;

	while (b) {
		if (b & 111) {
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
		pref[i] = (text[i] - 'a' + 1) * powerFunc(p, 31);
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

		if (newHash == (patternHash * powerFunc(p, i)) % mod)
			cout << i << endl;
	}
}