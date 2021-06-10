vector<int> primeFactors(int n) {
	vector<int> factors;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				factors.push_back(i);
				n /= i;
			}
		}
	}

	if (n != 1)
		factors.push_back(n);


	return factors;
}