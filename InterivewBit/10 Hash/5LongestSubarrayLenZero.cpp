/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Longest subarray with zero as sum
vector<int> Solution::lszero(vector<int> &A) {
    unordered_map<int, int> idx;
    int res = 0;
    int start = 0;
    int n = A.size();

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        if (sum == 0) {
            start = 0;
            res = i + 1;
        }

        if (idx.find(sum) == idx.end())
            idx[sum] = i;

        if (idx.find(sum) != idx.end()) {
            if (res < (i - idx[sum])) {
                res = i - idx[sum];
                start = idx[sum] + 1;
            }
        }
    }

    // cout<<start<<" "<<res<<" ";
    vector<int> ans = vector<int> (A.begin() + start, A.begin() + start + res);
    return ans;
}
