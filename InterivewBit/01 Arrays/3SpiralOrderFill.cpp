/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Fill num in spiral order
vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> res(A, vector<int>(A, 0)); // Initialize with zero
    int num = 1;
    int n = A;

    // Spiral order traversal of the matrix
    int rs = 0, re = n - 1, cs = 0, ce = n - 1;
    while (rs <= re and cs <= ce) {
        // Left to right
        for (int c = cs; c <= ce; c++) {
            res[rs][c] = num++;
        }
        rs++;

        // Top to down
        for (int r = rs; r <= re; r++) {
            res[r][ce] = num++;
        }
        ce--;

        // Right to left with a check for overflow
        if (rs < re) {
            for (int c = ce; c >= cs; c--) {
                res[re][c] = num++;
            }
            re--;
        }

        // Bottom to top with a check for overflow
        if (cs < ce) {
            for (int r = re; r >= rs; r--) {
                res[r][cs] = num++;
            }
            cs++;
        }
    }

    return res;
}
