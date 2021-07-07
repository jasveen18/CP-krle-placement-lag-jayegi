/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Three Sum zeros
vector<vector<int> > Solution::threeSum(vector<int> &A) {
    set<vector<int>> res;
    sort(A.begin(), A.end());
    int n = A.size();

    for (int i = 0; i < n - 2; i++) {
        int start = i + 1, end = n - 1;
        while (start < end) {
            if (A[i] == INT_MIN and  A[start] == INT_MIN) {
                start++;
                continue;
            }
            if (A[start] == INT_MAX and A[end] == INT_MAX) {
                end--;
                continue;
            }

            long long int sumhere = A[i] + A[start] + A[end];
            if (sumhere == 0) {
                // cout<<sumhere<<" "<<A[i] <<" "<< A[start]<<" ";
                res.insert({A[i], A[start], A[end]});
                start++; end--;
            } else if (sumhere < 0)
                start++;
            else
                end--;
        }
    }

    vector<vector<int>> ans;
    for (auto el : res)
        ans.push_back(el);
    return ans;
}
