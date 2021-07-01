/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the path for the rat to reach end.

bool ratInMaze(vector<vector<int>> &m, int i, int j, string currSeq, vector<string> &res) {
	// Base Case
	if (i == m.size() - 1 and j == m[0].size() - 1) {
		res.push_back(currSeq);
		return false;
	}

	// If rat goes out of grid
	if (i < 0 or j < 0 or i >= m.size() or j >= m[0].size())
		return false;

	// If rat encounters an obstacle
	if (m[i][j] == 0)
		return false;

	// If we are going further in this path, mark as visited
	m[i][j] = 0;
	// cout << i << " " << j << endl;
	bool down = ratInMaze(m, i + 1, j, currSeq + 'D', res);
	bool left = ratInMaze(m, i, j - 1, currSeq + 'L', res);
	bool right = ratInMaze(m, i, j + 1, currSeq + 'R', res);
	bool up = ratInMaze(m, i - 1, j, currSeq + 'U', res);

	// If we find a path
	if (up or down or left or right)
		return true;

	// Backtrack
	m[i][j] = 1;
	return false;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
	string curr = "";
	vector<string> res;

	if (m[m.size() - 1][m[0].size() - 1] == 0)
		return {};

	ratInMaze(m, 0, 0, curr, res);
	return res;
}