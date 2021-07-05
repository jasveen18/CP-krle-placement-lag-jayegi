/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Rotate Matrix Clockwise 90
void Solution::rotate(vector<vector<int> > &A) {
    // Approach -
    // 1. Take the transpose of matrix
    // 2. Reverse all the rows
    int n = A.size();

    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                swap(A[i][j], A[j][i]);
            }
        }
    }

    // Reverse
    for (int i = 0; i < n; i++) {
        reverse(A[i].begin(), A[i].end());
    }

    return;
}
