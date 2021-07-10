/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Two out of three. Hashing OP.
vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    set<int> res;

    unordered_map<int, int> one;
    unordered_map<int, int> two;
    unordered_map<int, int> three;

    for (int i = 0; i < A.size(); i++) {
        one[A[i]]++;
    }
    for (int i = 0; i < B.size(); i++) {
        two[B[i]]++;
    }
    for (int i = 0; i < C.size(); i++) {
        three[C[i]]++;
    }

    for (auto el : one) {
        if (two.find(el.first) != two.end() or three.find(el.first) != three.end())
            res.insert(el.first);
    }

    for (auto el : two) {
        if (three.find(el.first) != three.end())
            res.insert(el.first);
    }

    vector<int> ans(res.begin(), res.end());
    return ans;
}
