/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Find the min difference between min and max.
long long findMinDiff(vector<long long> a, long long n, long long m) {
    sort(a.begin(), a.end());

    int minDifference = INT_MAX;

    for (int i = 0; i < n - m + 1; i++) {
        int minChocolates = a[i];
        int maxChocolates = a[i + m - 1];

        minDifference = min(minDifference, (maxChocolates - minChocolates));
    }

    return minDifference;
}