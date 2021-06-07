bool longestPathWithHurdles(vector<vector<int>> grid, int i, int j, int currRouteLen, int &maxRouteLen) {
	// Base Case
	if (i == grid.size() and j == grid[0].size()) {
		maxRouteLen = max(maxRouteLen, currRouteLen);
		return false;
	}

	// Out of bounds
	if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
		return false;

	// Hurdles or Re-visit
	if (grid[i][j] == 0)
		return false;

	// Recursive Cases
	grid[i][j] = 0;

	bool d = longestPathWithHurdles(grid, i - 1, j, currRouteLen + 1, maxRouteLen);
	bool l = longestPathWithHurdles(grid, i, j - 1, currRouteLen + 1, maxRouteLen);
	bool u = longestPathWithHurdles(grid, i + 1, j, currRouteLen + 1, maxRouteLen);
	bool r = longestPathWithHurdles(grid, i, j + 1, currRouteLen + 1, maxRouteLen);

	if (d or l or u or r)
		return true;

	// Backtrack
	grid[i][j] = 1;
	return false;
}