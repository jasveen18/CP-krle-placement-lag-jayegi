bool generateAllPaths(vector<vector<int>> &m, int i, int j, string currPath, vector<string> &paths) {
	if (i == m.size() - 1 and j == m[0].size() - 1) {
		currPath += to_string(m[i][j]);
		paths.push_back(currPath);
		return false;
	}

	// Out of bound case
	if (i < 0 or j < 0 or i >= m.size() or j >= m[0].size())
		return false;

	// Traverse the paths
	bool down = printAllPaths(m, i + 1, j, currPath + to_string(m[i][j]), paths);
	bool right = printAllPaths(m, i, j + 1, currPath + to_string(m[i][j]), paths);

	return down or right;
}


bool mainGeneratePaths(vector<vector<int>> &m) {
	string res = "";
	vector<string> r;
	printAllPaths(m, 0, 0, res, r);
	return r;
}