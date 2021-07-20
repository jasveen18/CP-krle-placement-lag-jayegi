/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Black Shapes
void dfs(vector<string>&A, vector<vector<bool>> &visited, int i, int j) {
    if (i < 0 or j < 0 or i >= A.size() or j >= A[0].size())
        return;

    if (A[i][j] == 'O')
        return;

    if (visited[i][j] == true)
        return;

    visited[i][j] = true;
    // Now search for its neighbors
    vector<int> delx{0, 0, -1, 1};
    vector<int> dely{1, -1, 0, 0};

    for (int k = 0; k < 4; k++) {
        int x = i + delx[k];
        int y = j + dely[k];

        dfs(A, visited, x, y);
    }

    return;
}

int Solution::black(vector<string> &A) {
    // BFS krke mark kr denge
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X' and visited[i][j] == false) {
                dfs(A, visited, i, j);
                res++;
            }
        }
    }

    return res;
}
