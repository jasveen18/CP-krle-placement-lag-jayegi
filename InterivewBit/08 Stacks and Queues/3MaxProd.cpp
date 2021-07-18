/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Max Special Product
int Solution::maxSpecialProduct(vector<int> &A) {
    // Question is literally talking about nearest greater to left and nearest greater to right.
    long long n = A.size();
    long long mod = 1e9 + 7;

    stack<pair<long long, long long>> ngl;
    stack<pair<long long, long long>> ngr;

    // Space to store the results
    vector<long long> lngIdx;
    vector<long long> rngIdx;

    for (long long i = 0; i < n; i++) {
        if (ngl.empty()) {
            lngIdx.push_back(0);
        } else {
            while (ngl.empty() == false and ngl.top().first <= A[i])
                ngl.pop();

            if (ngl.empty())
                lngIdx.push_back(0);
            else
                lngIdx.push_back(ngl.top().second % mod);
        }

        ngl.push({A[i], i});
    }

    for (long long i = n - 1; i >= 0; i--) {
        if (ngr.empty()) {
            rngIdx.push_back(0);
        } else {
            while (ngr.empty() == false and ngr.top().first <= A[i])
                ngr.pop();

            if (ngr.empty())
                rngIdx.push_back(0);
            else
                rngIdx.push_back(ngr.top().second % mod);
        }

        ngr.push({A[i], i});
    }
    reverse(rngIdx.begin(), rngIdx.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, lngIdx[i] * rngIdx[i]);
    }

    return (ans % mod);
}
