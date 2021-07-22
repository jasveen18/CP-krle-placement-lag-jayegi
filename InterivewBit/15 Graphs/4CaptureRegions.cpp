/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a 2D character matrix A of size N x M, containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

//  A = [  [X, X, X, X],
//         [X, O, O, X],
//         [X, X, O, X],
//         [X, O, X, X]
//      ]

// Output 1:

//  A = [  [X, X, X, X],
//         [X, X, X, X],
//         [X, X, X, X],
//         [X, O, X, X]
//      ]

void dfs(vector<vector<char>> &A, int i, int j, vector<vector<int>> &status) {
    if (i < 0 or j < 0 or i >= A.size() or j >= A[0].size())
        return;

    if (status[i][j] != 0)
        return;

    if (A[i][j] == 'X')
        return;

    status[i][j] = 1;

    vector<int> delx{ -1, 1, 0, 0};
    vector<int> dely{0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int x = i + delx[k];
        int y = j + dely[k];

        dfs(A, x, y, status);
    }

    return;
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();

    // Not surrounded -> 1, not visited -> 0, rest -1
    vector<vector<int>> status(n, vector<int> (m, 0));

    // Edges wale 0 hi not surronded honge, and the connected 0s from that
    for (int i = 0; i < n; i++) {
        if (A[i][0] == 'O' and status[i][0] == 0)
            dfs(A, i, 0, status);
        if (A[i][m - 1] == 'O' and status[i][m - 1] == 0)
            dfs(A, i, m - 1, status);
    }

    for (int j = 1; j < m - 1; j++) {
        if (A[0][j] == 'O' and status[0][j] == 0)
            dfs(A, 0, j, status);
        if (A[n - 1][j] == 'O' and status[n - 1][j] == 0)
            dfs(A, n - 1, j, status);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'O' and status[i][j] != 1)
                A[i][j] = 'X';
        }
    }

    return;
}
