/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min number of rooms required
struct sortEnd {
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];
    }
};

int Solution::solve(vector<vector<int> > &A) {
    // Sort by start time
    sort(A.begin(), A.end());
    int n = A.size();
    int res = 0;
    int curr = 0;

    priority_queue<vector<int>, vector<vector<int>>, sortEnd> ongoing;

    for (int i = 0; i < n; i++) {
        // Current meeting
        int time = A[i][0];
        ongoing.push(A[i]);

        while (ongoing.empty() == false and ongoing.top()[1] <= time)
            ongoing.pop();

        res = max((int)ongoing.size(), res);
    }

    return res;
}
