bool isValid(int i, int j, vector<vector<int>> grid) {
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
		return false;

	return true;
}


void markUnsafeTiles(vector<vector<int>> &grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			// If we have a landmine here, we will mark the neighboring tiles as unsafe
			if (grid[i][j] == 0) {
				// Up
				if (isValid(i - 1, j, grid))
					grid[i - 1][j] = -1;
				// Down
				if (isValid(i + 1, j, grid))
					grid[i + 1][j] = -1;
				// Left
				if (isValid(i, j - 1, grid))
					grid[i][j - 1] = -1;
				// Right
				if (isValid(i, j + 1, grid))
					grid[i][j + 1] = -1;
			}
		}
	}

	// Now mark all the unsafe areas
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == -1)
				grid[i][j] = 0;
		}
	}

	return;
}


void findShortestPath(vector<vector<int>> &grid, int i, int j, int currDistance, int &minDistance) {
	// Base Case
	if (j == grid[0].size()) {
		minDistance = min(minDistance, currDistance);
		return;
	}

	// Is we encounter the unsafe position
	if (grid[i][j] == 0)
		return;

	// Pruning
	if (currDistance > minDistance)
		return;

	// Recursive Case
	// Mark as visited and then visit in all four directions
	grid[i][j] = 0;
	// Down, Left, Right, Up
	findShortestPath(grid, i + 1, j, currDistance + 1, minDistance);
	findShortestPath(grid, i, j - 1, currDistance + 1, minDistance);
	findShortestPath(grid, i, j + 1, currDistance + 1, minDistance);
	findShortestPath(grid, i - 1, j, currDistance + 1, minDistance);

	// Backtrack
	grid[i][j] = 1;
	return;
}

// Driver Function
int findMinDistance(vector<vector<int>> &grid) {
	int currDist = 0;
	int minDist = INT_MAX;

	for (int i = 0; i < grid.size(); i++) {
		findShortestPath(grid, i, 0, currDistance, minDist);
	}

	return minDist;
}