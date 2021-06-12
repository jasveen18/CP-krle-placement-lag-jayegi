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
	long long int textHash = polyHashString(text.substr(0, m));
	long long int patternHash = polyHashString(pattern);

	// If first se hi match kr gya, print the index, then move on.
	if (textHash == patternHash) {
		cout << 0 << " ";
	}

	// Let's check now with rolling hash.
	for (int i = 1; i + m <= n; i++) {
		long long int hashNext = textHash;
		// Remove the i-1 th char.
		hashNext = (hashNext - (text[i - 1] - 'a' + 1) + mod) % mod;
		// Now we need to divide by p.
		hashNext *= inverseFunc(primeNum);
		hashNext %= mod;

		// Add the new character
		hashNext += ((text[i + m - 1] - 'a' + 1) * powerFunc(primeNum, m - 1));
		hashNext %= mod;

		// Check if hash is equal
		// cout << hashNext << " " << patternHash << endl;
		if (hashNext == patternHash)
			cout << i << " ";

		// Modify to move on to next window
		textHash = hashNext;
	}
}