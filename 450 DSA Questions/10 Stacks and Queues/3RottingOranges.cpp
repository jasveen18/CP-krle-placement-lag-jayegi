/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rotting oranges, simple BFS
int orangesRotting(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();

    // {{x, y}, time}
    queue<pair<pair<int, int>, int>> q;

    // Take all the rotten oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }

    // cout<<q.size()<<endl;
    vector<int> delx{ -1, 1, 0, 0};
    vector<int> dely{0, 0, -1, 1};

    // Start now
    while (q.empty() == false) {
        auto idx = q.front().first;
        auto timeTaken = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            // Check for out of bounds
            int x = idx.first + delx[i];
            int y = idx.second + dely[i];
            if (x >= 0 and x < n and y >= 0 and y < m) {
                if (grid[x][y] == 1) {
                    grid[x][y] = 2;

                    q.push({{x, y}, timeTaken + 1});
                    ans = max(ans, timeTaken + 1);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return ans;
}