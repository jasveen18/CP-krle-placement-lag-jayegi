/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Four sum
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int>> res;

    sort(A.begin(), A.end());
    int n = A.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int start = j + 1, end = n - 1;
            int sumThree = A[i] + A[j];

            while (start < end) {
                int sum = sumThree + A[start] + A[end];

                if (sum == B) {
                    res.push_back({A[i], A[j], A[start], A[end]});
                    start++; end--;
                }
                if (sum > B)
                    end--;
                if (sum < B)
                    start++;
            }
        }
    }

    sort(res.begin(), res.end());
    auto it = unique(res.begin(), res.end());

    res.erase(it, res.end());
    return res;
}
