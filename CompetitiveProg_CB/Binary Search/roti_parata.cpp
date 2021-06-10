bool canCook(vector<int> &ranks, int cooks, int parata, int timeGiven) {
    int parataCooked = 0;

    for (int i = 0; i < cooks; i++) {
        int timeGivenToCook = timeGiven;
        int multiplier = 1;

        while (timeGivenToCook - (ranks[i] * multiplier) >= 0) {
            parataCooked++;
            timeGivenToCook -= (ranks[i] * multiplier);
            multiplier += 1;
        }

        if (parataCooked >= parata)
            return true;
    }

    return false;
}


int minTime(vector<int> &ranks, int cooks, int parata) {

    // Time taken by the fastest cook to cook all parata.
    int fastestCook = *min_element(ranks.begin(), ranks.end());
    int p = 0;
    long long int timeTaken = 0;
    while (p < parata) {
        timeTaken += fastestCook;
        fastestCook += fastestCook;
        p++;

        if (timeTaken > 1e9) {
            timeTaken = 1e17;
            break;
        }
    }

    // Binary search on time
    int low = 0, high = timeTaken, ans = timeTaken;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canCook(ranks, cooks, parata, mid)) {
            ans = min(ans, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}