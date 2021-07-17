/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Return the kth row of pascal triangle
vector<int> Solution::getRow(int rowIndex) {
    vector<vector<int>> res;
    vector<int> temp{1};

    res.push_back(temp);

    for (int i = 2; i <= rowIndex + 1; i++) {
        vector<int> row(i, 0);

        // First num
        row[0] = 1;
        // Last Num
        row[i - 1] = 1;

        // Middle nums
        for (int j = 1; j < i - 1; j++) {
            row[j] = res[i - 2][j] + res[i - 2][j - 1];
        }

        res.push_back(row);
    }

    return res[rowIndex];
}
