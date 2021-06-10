/*
A Boston number is a composite number,
the sum of whose digits is the sum of
the digits of its prime factors obtained
as a result of prime factorization (excluding 1 ).
The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 .
For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number
since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7.
Write a program to check whether a given integer is a Boston number.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> primes(1e5, 0);

void sieve() {
	for (int i = 2; i < 1e5; i++) {
		if (primes[i] == 0) {
			for (int j = 2 * i; j < 1e5; j += i) {
				primes[j] = 1;
			}
		}
	}

	primes[2] = 0;
	primes[1] = 1;
}


void digitSum(ll &sum, ll n) {
	while (n) {
		sum += n % 10;
		n /= 10;
	}
}


void primeFactSum(ll &sum, ll n) {
	ll x = sqrt(n);
	int i = 2;
	while (n > 1 and i < x) {
		if (primes[i] == 0 and n % i == 0) {
			digitSum(sum, i);
			n /= i;
		} else {
			i++;
		}
	}

	if (primes[n] == 0)
		digitSum(sum, n);
}


int main() {
	sieve();
	ll n;
	cin >> n;

	ll digSum = 0;
	digitSum(digSum, n);

	ll primeSum = 0;
	primeFactSum(primeSum, n);

	if (digSum == primeSum)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}