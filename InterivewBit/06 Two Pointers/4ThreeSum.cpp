/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Three Sum
int Solution::threeSumClosest(vector<int> &A, int B) {
    int n = A.size();
    int close = INT_MAX;
    int ans = 0;

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        int start = i + 1, end = n - 1;
        while (start < end) {
            long long int sumHere = A[i] + A[start] + A[end];
            if (abs(sumHere - B) < close) {
                close = abs(sumHere - B);
                ans = sumHere;
            } else if (B - sumHere > 0)
                start++;
            else
                end--;
        }
    }

    return ans;
}
