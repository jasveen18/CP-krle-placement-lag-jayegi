/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Cut wood
bool requirementMet(vector<int> &arr, int b, int mid) {
    long long int wood = 0;
    for (int i = 0; i < arr.size(); i++) {
        wood += max(0, arr[i] - mid);
    }

    return wood >= b;
}

int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n = A.size();
    int maxEl = *max_element(A.begin(), A.end());
    int start = 0, end = maxEl;
    long long int res = INT_MAX;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (requirementMet(A, B, mid)) {
            res = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return res;
}
