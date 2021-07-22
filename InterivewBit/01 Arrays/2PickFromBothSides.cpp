/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - You can pick B elements from either left or right end of the array A to get maximum sum.

// Find and return this maximum possible sum.
int Solution::solve(vector<int> &arr, int B) {
    int n = arr.size();
    int sum = 0;
    int res = 0;

    for (int i = 0 ; i < B ; i++)
        res += arr[i];

    sum = res;
    for (int i = 0 ; i < B ; i++)
    {
        sum -= arr[B - 1 - i];
        sum += arr[n - 1 - i];

        res = max(res, sum);
    }
    return res;
}
