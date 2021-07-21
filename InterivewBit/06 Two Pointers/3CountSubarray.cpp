/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Count subarrays with sum < B
int Solution::solve(vector<int> &A, int B) {
    int sum = 0;
    int res = 0;
    int n = A.size();

    int i = 0, j = 0;

    while (j < n) {
        sum += A[j];

        if (sum < B) {
            res += (j - i + 1);
            j++;
        } else if (sum >= B) {
            while (sum >= B) {
                sum -= A[i];
                i++;
            }

            res += (j - i + 1);
            j++;
        }
    }

    return res;
}