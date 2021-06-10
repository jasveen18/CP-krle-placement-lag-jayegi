// Prime Sieve ka code.
const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void bitset_prime_sieve() {
	// Set all the bits to prime
	b.set();

	b[0] = b[1] = 0;
	for (ll i = 2; i <= n; i++) {

		if (b[i]) {
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i)
				b[j] = 0;

		}

	}
}

// ----------------
// Factorisation
vector<int> primeFactors(int n, vector<int> &primes) {
	vector<int> factors;

	int i = 0;
	int p = primes[0];

	while (p * p <= n) {
		if (m % p == 0) {
			while (m % p == 0) {
				factors.push_back(p);
				m = m / p;
			}
		}

		i++;
		p = primes[i];
	}

	// Check for the last prime factor
	if (n != 1)
		factors.push_back(n);

	return factors;
}