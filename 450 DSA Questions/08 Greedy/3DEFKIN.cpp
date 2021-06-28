/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the max undefended field area.
int findMaxUndefendedBlock(int width, int height, int n, vector<int> &x, vector<int> &y) {
	// Sort the co-ordinates
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	// Find the max difference between any 2 place
	int maxDiffX = x[0] - 1;
	int maxDiffY = y[0] - 1;


	for (int i = 1; i < n; i++) {
		maxDiffX = max(maxDiffX, x[i] - x[i - 1] - 1);
		maxDiffY = max(maxDiffY, y[i] - y[i - 1] - 1);
	}

	// For the last tower, we need to match with end of field
	maxDiffX = max(maxDiffX, width - x[n - 1]);
	maxDiffY = max(maxDiffY, height - y[n - 1]);

	return maxDiffX * maxDiffY;
}