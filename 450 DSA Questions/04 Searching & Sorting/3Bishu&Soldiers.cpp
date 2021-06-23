/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/

void printBeatenSoldiers(vector<int> &powers, vector<int> &queries, int n, int q) {
	sort(powers.begin(), powers.end());

	// Take prefix sum to return the sum in O(1)
	vector<int> sumPowers(n);
	sumPowers[0] = powers[0];
	for (int i = 1; i < n; i++)
		sumPowers[i] = sumPowers[i - 1] + powers[i];

	// Process each queries
	for (int i = 0; i < q; i++) {
		int soldiersBeaten = upper_bound(powers.begin(), powers.end(), queries[i]) - powers.begin();

		// Print the results.
		cout << soldiersBeaten << " " << sumPowers[soldiersBeaten - 1] << endl;;
	}
}