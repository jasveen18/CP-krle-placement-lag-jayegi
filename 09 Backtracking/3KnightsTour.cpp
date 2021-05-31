// T - O(8 ^ (N*n))
bool knightTour(vector<vector<int>> &grid, int i, int j, int blocksFilled) {
	// Base Case
	if (blocksFilled == grid.size() * grid.size())
		return true;

	// Check for invalid cases
	// Out of bound
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid.size())
		return false;

	// If already visited
	if (grid[i][j] != -1)
		return false;

	// Recursive Cases
	// We can move at 8 places
	vector<int> movesX{2, 1, -1, -2, -2, -1, 1, 2};
	vector<int> movesY{1, 2, 2, 1, -1, -2, -2, -1};

	// Place the knight here
	grid[i][j] = blocksFilled;
	bool subProbPossible = false;
	for (int k = 0; k < 8; k++) {
		subProbPossible = knightTour(grid, i + movesX[k],
		                             j + movesY[k], blocksFilled + 1);

		if (subProbPossible)
			return true;
	}

	// Backtracking
	grid[i][j] = -1;
	return false;
}


void knightDriver(int n) {
	vector<vector<int>> grid(n, vector<int> (n, -1));

	bool possible = knightTour(grid, 0, 0, 0);

	if (possible) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;

		}
	}
}