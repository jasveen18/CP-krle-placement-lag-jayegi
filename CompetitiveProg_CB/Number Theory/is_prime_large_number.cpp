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


bool isPrime(long long No) {
	if (No <= n)
		return b[No] == 1 ? true : false;

	for (ll i = 0; primes[i] * primes[i] <= No; i++) {
		if (No % primes[i] == 0)
			return false;
	}

	return true;
}