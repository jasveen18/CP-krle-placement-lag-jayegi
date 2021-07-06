// ** Traverlling Sales Man - DP with Bitmasking ** //
// O(N!) -> O(2^N * N)

// Set of cities, is the visited cities and we are using the bits of the number to represent this.
// num = 00000
// num = 00001, means ki A is visited
// We are using this in DP(next solution), to hash the value very easily.
int tspSolve(vector<vector<int>> &dist, int setOfCities, int city, int n, vector<vector<int>> &dp) {
	// Base Case -     2^n - 1, 111111.. aisa kuch mtlb sab jagah pahuch gye
	if (setOfCities == ((1 << n) - 1)) {
		return dist[city][0]; // Return the cost of current city to source
	}


	// Dp lookup
	if (dp[setOfCities][city] != -1)
		return dp[setOfCities][city];

	// Recursive Case - Try all possible options -
	int ans = INT_MAX;

	for (int choice = 0; choice < n; choice++) {
		// Need to check if city is visited or not, check the ith bit.
		if ((setOfCities & (1 << choice)) == 0) {

			int setThisCity = (setOfCities | (1 << choice)); // mark this city as true
			int subProblem = dist[city][choice] + tspSolve(dist, setThisCity, choice, n, dp);
			ans = min(ans, subProblem);

		}
	}

	return dp[setOfCities][city] = ans;
}


int travellingSalesMan(vector<vector<int>> &adjMatrix, int n) {
	vector<vector<int>> dp(1 << n, vector<int> (n, -1));
	return tspSolve(adjMatrix, 1, n, dp);
}