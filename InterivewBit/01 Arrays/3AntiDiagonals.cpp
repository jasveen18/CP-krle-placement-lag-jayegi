/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Print the anti diagonals
vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> res(2 * (n - 1) + 1);

    // Make the array as (i + j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i + j].push_back(A[i][j]);
        }
    }

    return res;
}
