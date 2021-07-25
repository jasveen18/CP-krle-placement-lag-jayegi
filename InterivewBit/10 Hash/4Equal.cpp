/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find A[i] + A[j] = A[k] + A[l]
vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int, pair<int, int>> idx;
    vector<vector<int>> res;
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sumHere = A[i] + A[j];

            if (idx.find(sumHere) == idx.end()) {
                idx[sumHere] = {i, j};
            } else {
                int x = idx[sumHere].first;
                int y = idx[sumHere].second;

                if (x != i and y != j and x != j and y != i) {
                    res.push_back({x, y, i, j});
                }
            }
        }
    }

    sort(res.begin(), res.end());
    return res[0];
}
