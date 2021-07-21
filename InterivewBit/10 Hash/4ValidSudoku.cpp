/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Check if sudoku is valid / not. Check only filled positions.
int Solution::isValidSudoku(const vector<string> &A) {
    // Valid ke lie, first of all pura row check krenge and pura column krenge

    // Row wise
    unordered_set<char> rows;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (A[i][j] == '.')
                continue;

            if (rows.find(A[i][j]) != rows.end())
                return 0;
            rows.insert(A[i][j]);
        }

        rows.clear();
    }

    // Column Wise
    unordered_set<char> cols;
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            if (A[i][j] == '.')
                continue;

            if (cols.find(A[i][j]) != cols.end())
                return 0;
            cols.insert(A[i][j]);
        }

        cols.clear();
    }

    // Now apne dabba m check kro
    unordered_set<char> dabba;
    bool a = true;
    for (int i = 0; i < 9; i++) {
        int rs = (i / 3) * 3;
        int cs = (i % 3) * 3;

        // cout<<rs<<" "<<cs<<" | ";

        for (int j = rs; j < rs + 3; j++) {
            for (int k = cs; k < cs + 3; k++) {

                // cout<<A[j][k]<<" ";

                if (A[j][k] == '.') continue;

                if (dabba.find(A[j][k]) != dabba.end())
                    return 0;
                dabba.insert(A[j][k]);
            }

            // cout<<"|";
        }
        // cout<<"||";
        dabba.clear();
    }

    return 1;
}
