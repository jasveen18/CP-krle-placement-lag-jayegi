/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the max rectangular area in histogram
int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();

    // We need to traverse both sides, and find the next smaller element
    // Nearest Smaller to left and Nearest Smaller to Right
    stack<pair<int, int>> nsl;
    stack<pair<int, int>> nsr;

    // Space to store the results
    vector<int> lnsIdx;
    vector<int> rnsIdx;

    // NSL pehle
    for (int i = 0; i < n; i++) {
        if (nsl.empty()) {
            lnsIdx.push_back(-1);
        } else {
            while (nsl.empty() == false and nsl.top().first >= A[i])
                nsl.pop();

            if (nsl.empty())
                lnsIdx.push_back(-1);
            else
                lnsIdx.push_back(nsl.top().second);
        }

        nsl.push({A[i], i});
    }

    // NSR ab
    for (int i = n - 1; i >= 0; i--) {
        if (nsr.empty()) {
            rnsIdx.push_back(n);
        } else {
            while (nsr.empty() == false and nsr.top().first >= A[i])
                nsr.pop();

            if (nsr.empty())
                rnsIdx.push_back(n);
            else
                rnsIdx.push_back(nsr.top().second);
        }

        nsr.push({A[i], i});
    }
    reverse(rnsIdx.begin(), rnsIdx.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, ((rnsIdx[i] - lnsIdx[i] - 1) * A[i]));
    }

    return ans;
}
