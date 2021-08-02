/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// 1. 933. Number of Recent Calls
class RecentCounter {
private:
	vector<int> pings;
	int i, j;
public:
	RecentCounter() {
		pings = vector<int>();
		i = -1;
		j = -1;
	}

	int ping(int t) {
		// First entry
		if (i == -1 and j == -1) {
			pings.push_back(t);
			i++; j++;
			return 1;
		}

		pings.push_back(t);
		j++;
		while (i < j and pings[i] + 3000 < pings[j])
			i++;

		return (j - i + 1);
	}
};


// 3. Shortest Bridge
class Solution {
	vector<int> delx{0, 0, -1, 1};
	vector<int> dely{ -1, 1, 0, 0};
public:
	void singledfs(int i, int j, vector<vector<int>>& grid, queue<pair<int, int>> &q) {
		if (i < 0 or j < 0 or i >= grid.size() or j >= grid[i].size() or grid[i][j] == 0 or grid[i][j] == 2)
			return;

		grid[i][j] = 2;
		q.push({i, j});
		for (int k = 0; k < 4; k++) {
			int x = i + delx[k];
			int y = j + dely[k];

			singledfs(x, y, grid, q);
		}

		return;
	}

	int shortestBridge(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		// BFS from any one of the island
		queue<pair<int, int>> q;
		bool done = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					singledfs(i, j, grid, q);
					done = true;
					break; // ek hi island ko process krna hai
				}

				if (done)
					break;
			}

			if (done)
				break;
		}

		int res = 0;
		while (q.empty() == false) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				pair<int, int> curr = q.front(); q.pop();

				grid[curr.first][curr.second] = -1; // processed
				for (int k = 0; k < 4; k++) {
					int x = curr.first + delx[k];
					int y = curr.second + dely[k];

					if (x >= 0 and y >= 0 and x < n and y < m) {
						if (grid[x][y] == 0) {
							grid[x][y] = -1;
							q.push({x, y});
						} else if (grid[x][y] == 1) {
							return res;
						}
					}
				}
			}

			res++;
		}

		return res;
	}
};