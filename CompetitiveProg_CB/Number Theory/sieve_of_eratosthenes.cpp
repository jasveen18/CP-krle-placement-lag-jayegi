// O(N * log log N), almost equal to O(N).
void prime_sieve(int *p) {

	// Mark all the odd numbers as prime
	for (ll i = 3; i <= 1000000; i += 2) {
		p[i] = 1;
	}

	// Sieve
	for (ll i = 3; i <= 1000000; i += 2) {
		// If the current number is not marked, it is prime.
		if (p[i] == 1) {
			for (ll j = i * i; j <= 1000000; j += i) {
				p[j] = 0;
			}
		}
	}

	// Special case
	p[2] = 1;
	p[1] = p[0] = 0;
}


// Using bitset to store larger space.
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