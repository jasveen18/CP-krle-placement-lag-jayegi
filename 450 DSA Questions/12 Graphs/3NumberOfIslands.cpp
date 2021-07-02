/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -
//Function to find the number of islands.
void visitAllNeighbors(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &vis) {
    // Base Case -
    if (i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size())
        return;

    if (grid[i][j] == '0' or vis[i][j] == true)
        return;

    vis[i][j] = true;

    // Now from here, go to all it's neighbors
    int dx [] = {0, 1, -1, 0, 1, 1, -1, -1};
    int dy [] = {1, 0, 0, -1, 1, -1, 1, -1};

    for (int k = 0; k < 8; k++)
        visitAllNeighbors(grid, i + dx[k], j + dy[k], vis);
}


int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] and grid[i][j] == '1') {
                visitAllNeighbors(grid, i, j, visited);
                res++;
            }
        }
    }

    return res;
}