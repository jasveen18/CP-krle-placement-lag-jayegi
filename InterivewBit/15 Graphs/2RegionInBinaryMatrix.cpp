/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Biggest area filled?
void dfs(vector<vector<int>> &A, vector<vector<bool>> &vis, int i, int j, int &count) {
    if (i < 0 or j < 0 or i >= A.size() or j >= A[0].size() or vis[i][j] == true or A[i][j] == 0)
        return;

    vis[i][j] = true;
    count++;

    vector<int> delx{0, 0, 1, -1, 1, 1, -1, -1};
    vector<int> dely{ -1, 1, 0, 0, 1, -1, 1, -1};

    for (int k = 0; k < 8; k++) {
        int x = i + delx[k];
        int y = j + dely[k];

        dfs(A, vis, x, y, count);
    }

    return;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    // DFS krenge
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == false) {
                int count = 0;
                dfs(A, vis, i, j, count);
                res = max(count, res);
            }
        }
    }

    return res;
}
