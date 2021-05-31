bool isValidPlace(int grid[N][N], int i, int j, int num) {
    // Check for row and columns
    for (int p = 0; p < N; p++) {
        // Row check
        if (grid[p][j] == num)
            return false;
        // Column check
        if (grid[i][p] == num)
            return false;
    }

    // Check the smaller grid.
    // Steps -
    // 1. get the starting and ending indexes of smaller grid
    // 2. iterate over all the nums and check

    int rowStart = (i / 3) * 3;
    int colStart = (j / 3) * 3;

    for (int r = rowStart; r < rowStart + 3; r++) {
        for (int c = colStart; c < colStart + 3; c++) {
            if (grid[r][c] == num)
                return false;
        }
    }

    return true;
}

//Function to find a solved Sudoku.
bool SolveSudoku(int grid[N][N], int i = 0, int j = 0)
{
    // Base Case
    if (i == N)
        return true;

    // Different cases to take care of
    if (j == N)
        return SolveSudoku(grid, i + 1, 0);

    if (grid[i][j] != 0)
        return SolveSudoku(grid, i, j + 1);

    // Recursive Case
    for (int num = 1; num <= 9; num++) {
        if (isValidPlace(grid, i, j, num)) {
            grid[i][j] = num;
            bool subProbSolved = SolveSudoku(grid, i, j + 1);

            if (subProbSolved)
                return true;
        }
    }

    // Backtrack because no solution found
    grid[i][j] = 0;
    return false;
}

//Function to print grids of the Sudoku.
void printGrid (int grid[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}