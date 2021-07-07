/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Search in Matrix
int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size(), m = A[0].size();
    int i = 0, j = m - 1;

    // Ladder traversal
    while (i < n and j >= 0) {
        if (A[i][j] == B)
            return 1;

        if (A[i][j] > B)
            j--;
        else
            i++;
    }

    return 0;
}
