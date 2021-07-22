/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Solve sudoku
int N = 9;

bool isValidPlace(vector<vector<char>> &A, int i, int j, int num) {
    char n = num + '0';

    // Row wise Check
    for (int x = 0; x < 9; x++) {
        if (A[i][x] == n) return false;
        if (A[x][j] == n) return false;
    }

    // Dabba m
    int rs = 3 * (i / 3);
    int cs = 3 * (j / 3);

    for (int x = rs; x < rs + 3; x++) {
        for (int y = cs; y < cs + 3; y++) {
            if (A[x][y] == n)
                return false;
        }
    }

    return true;
}

//Function to find a solved Sudoku.
bool SolveSudoku(vector<vector<char>> &grid, int i = 0, int j = 0)
{
    // Base Case
    if (i == N)
        return true;

    // Different cases to take care of
    if (j == N)
        return SolveSudoku(grid, i + 1, 0);

    if (grid[i][j] != '.')
        return SolveSudoku(grid, i, j + 1);

    // Recursive Case
    for (int num = 1; num <= 9; num++) {
        if (isValidPlace(grid, i, j, num)) {
            grid[i][j] = num + '0';
            bool subProbSolved = SolveSudoku(grid, i, j + 1);

            if (subProbSolved)
                return true;
        }
    }

    // Backtrack because no solution found
    grid[i][j] = '.';
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    N = A.size();
    SolveSudoku(A, 0, 0);

    return;
}
