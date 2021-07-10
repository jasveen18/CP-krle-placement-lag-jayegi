/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find permutations of the array
void permuteThisVector(vector<int> &a, int i, set<vector<int>> &res) {
    // Base Case
    if (i == a.size()) {
        res.insert(a);
        return;
    }

    // Recursive Case
    for (int j = i; j < a.size(); j++) {
        swap(a[i], a[j]);
        permuteThisVector(a, i + 1, res);

        // Backtrack
        swap(a[i], a[j]);
    }

    return;
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    set<vector<int> > res;
    int i = 0;

    permuteThisVector(A, i, res);

    vector<vector<int>> ans(res.begin(), res.end());
    return ans;
}

