/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the first n rows of pascal triangle
vector<vector<int> > Solution::solve(int numRows) {
    if (numRows == 0)
        return {};

    vector<vector<int>> res;
    vector<int> temp{1};

    res.push_back(temp);

    for (int i = 2; i <= numRows; i++) {
        vector<int> row(i, 0);

        // First num
        row[0] = 1;
        // Last Num
        row[i - 1] = 1;

        for (int j = 1; j < i - 1; j++) {
            row[j] = res[i - 2][j] + res[i - 2][j - 1];
        }

        res.push_back(row);
    }

    return res;
}
