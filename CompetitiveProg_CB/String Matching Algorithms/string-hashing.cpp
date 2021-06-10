// Convert a string to a integer -
// We will define some norms.

// 1. Map the number with string.
// a->1, b->2, c->3, ..... z->26.

// 2. Take a prime number, p.

// 3. Then the string will be, for example s = "abcd"
// then, hash function = (a * p^0) + (b * p^1) + (c * p^2) + (d * p^4)

// This number can grow very big, therefore we will do mod.
// Now since we are doing mod, then there can be collisions
// It is called high probablity correct solution. It will work for online judge,
// but not good for production.


// Code -
long long int polyHashString(string s) {
	long long int primeNum = 31, m = 1e9 + 7;
	long long int hashValue = 0;
	long long int powerNow = 1;

	// Hash function
	for (int i = 0; i < n; i++) {
		hashValue += powerNow * (s[i] - 'a' + 1);
		powerNow *= primeNum;
		powerNow %= m;
		hashValue %= m;
	}

	return hashValue;
}