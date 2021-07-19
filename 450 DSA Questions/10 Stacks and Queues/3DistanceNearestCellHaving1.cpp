/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Distance of nearest cell having one
vector<vector<int>>nearest(vector<vector<int>>grid) {
	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> res(n, vector<int> (m, 0));

	// {{i, j}, dist}
	queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1)
				q.push({{i, j}, 0});
		}
	}

	vector<int> delx{1, -1, 0, 0};
	vector<int> dely{0, 0, -1, 1};

	while (q.empty() == false) {
		auto idx = q.front().first;
		auto dist = q.front().second; q.pop();

		// res[idx.first][idx.second] = dist;

		for (int i = 0; i < 4; i++) {
			int x = idx.first + delx[i];
			int y = idx.second + dely[i];

			if (x >= 0 and x < n and y >= 0 and y < m) {
				if (grid[x][y] == 0) {
					grid[x][y] = 1;
					res[x][y] = dist + 1;
					q.push({{x, y}, dist + 1});
				}
			}
		}
	}

	return res;
}