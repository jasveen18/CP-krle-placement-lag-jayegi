/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find all configs of 'n*n' board
#include<bitset>
bitset<30> col, d1, d2;
bool isSafeForQueen(vector<string> &board, int i, int j, int n) {
    // Out of bounds
    if (i < 0 or j < 0 or i > n or j > n)
        return false;

    if (col[j] or d1[i - j + n - 1] or d2[i + j])
        return false;

    return true;
}


bool findMyQueens(vector<string> &board, vector<vector<string>> &res, int &n, int i) {
    // Base Case - Solution mil gya
    if (i == n) {
        res.push_back(board);
        return false; // To keep on finding
    }

    // Recusive Case
    for (int k = 0; k < n; k++) {
        if (isSafeForQueen(board, i, k, n)) {
            board[i][k] = 'Q';

            // Update the hashed places
            col[k] = d1[i - k + n - 1] = d2[i + k] = 1;

            bool kyaQueenRakhPaaye = findMyQueens(board, res, n, i + 1);

            if (kyaQueenRakhPaaye)
                return true;

            // Backtrack
            board[i][k] = '.';
            col[k] = d1[i - k + n - 1] = d2[i + k] = 0;
        }
    }

    return false;
}


vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> res;
    vector<string> board;
    col.reset();
    d1.reset();
    d2.reset();

    if (A == 1) {
        return {{"Q"}};
    }

    // Make the empty board
    string line = "";
    for (int i = 0; i < A; i++)
        line += '.';
    for (int i = 0; i < A; i++)
        board.push_back(line);

    // Find the queens
    int i = 0, j = 0;
    bool ans = findMyQueens(board, res, A, i);

    if (A <= 3)
        return {};

    return res;
}
