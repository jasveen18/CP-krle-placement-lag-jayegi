vector<vector<ll>> multiplyMatrix(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> C(2, vector<ll> (2));
	ll size = 2;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				C[i][j] =  (C[i][j] + (A[i][k] * B[k][j] % MOD)) % MOD;
			}
		}
	}

	return C;
}


vector<vector<ll>> powerMatrix(vector<vector<ll>> A, ll p) {
	if (p == 1)
		return A;

	if (p & 1)
		return multiplyMatrix(A, powerMatrix(A, p - 1));

	vector<vector<ll>> X = powerMatrix(A, p / 2);
	return multiplyMatrix(X, X);
}


ll fastFib(ll n) {
	vector<ll> f1 = {0, 1};
	vector<vector<ll>> transformationMatrix = {{0, 1}, {1, 1}};

	// transformationMatrix ^ (n-1) on the same matrix.
	transformationMatrix = powerMatrix(transformationMatrix, n - 1);

	// Multiply by f1 to get the answer.
	ll res = 0;
	for (int i = 0; i < 2; i++) {
		res = (res + ((transformationMatrix[1][i] * f1[i]) % MOD)) % MOD;
	}

	return res;
}