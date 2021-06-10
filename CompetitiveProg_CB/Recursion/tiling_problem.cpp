#define mod 1000000007
int tiling[100000] = {0};

int tilingProblem(int n, int m) {
	if (n < m)
		return 1;
	if (tiling[n])
		return tiling[n];

	return tiling[n] = (tilingProblem(n - 1, m) + tilingProblem(n - m, m)) % mod;
}