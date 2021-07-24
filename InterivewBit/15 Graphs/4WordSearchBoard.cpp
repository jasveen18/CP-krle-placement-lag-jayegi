/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Word Search Board
int dfsKro(vector<string> &A, string B, int idx, int i, int j) {
    if (idx == B.size()) {
        return 1;
    }

    vector<int> delx{1, -1, 0, 0};
    vector<int> dely{0, 0, 1, -1};

    for (int k = 0; k < 4; k++) {
        int x = i + delx[k];
        int y = j + dely[k];

        if (x >= 0 and y >= 0 and x < A.size() and y < A[0].size() and (A[x][y] == B[idx])) {
            int hua = dfsKro(A, B, idx + 1, x, y);
            if (hua == 1)
                return 1;
        }
    }

    return 0;
}


int Solution::exist(vector<string> &A, string B) {
    string curr = "";

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            if (A[i][j] == B[0]) {
                int hua = dfsKro(A, B, 1, i, j);

                if (hua == 1)
                    return true;
            }
        }
    }

    return false;
}
