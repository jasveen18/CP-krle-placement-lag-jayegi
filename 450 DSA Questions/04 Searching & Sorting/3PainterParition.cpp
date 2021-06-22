/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Variation of Painter Parition in LC.
// 1482. Minimum Number of Days to Make m Bouquets
bool isPossibleToMake(vector<int> &bloom, int m, int k, int time) {
    int bouqPossible = 0;
    int n = bloom.size();
    int runningFlowers = 0;

    for (int i = 0; i < n; i++) {
        if (time >= bloom[i]) {
            runningFlowers++;
        } else {
            runningFlowers = 0;
        }

        if (runningFlowers == k) {
            bouqPossible++;
            runningFlowers = 0;
        }
    }

    return bouqPossible >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int totalFlowersRequired = m * k;
    int n = bloomDay.size();

    if (totalFlowersRequired > n)
        return -1;

    // Binary Search Problem
    int start = 0, end = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // Is it possible to make bouquets?
        if (isPossibleToMake(bloomDay, m, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}