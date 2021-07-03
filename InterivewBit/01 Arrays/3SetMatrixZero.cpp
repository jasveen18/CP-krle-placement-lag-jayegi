/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
void Solution::setZeroes(vector<vector<int> > &A) {
    unordered_set<int> rows;
    unordered_set<int> cols;

    int n = A.size();
    int m = A[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    // Make the rows = 0.
    for (auto el : rows) {
        // Make the whole row as zero
        for (int j = 0; j < m; j++)
            A[el][j] = 0;
    }

    for (auto el : cols) {
        // Make the whole column as zero
        for (int i = 0; i < n; i++)
            A[i][el] = 0;
    }

    return;
}
