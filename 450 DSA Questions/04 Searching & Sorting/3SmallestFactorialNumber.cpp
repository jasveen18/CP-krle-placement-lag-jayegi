/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - find the smallest number whose factorial contains at least n trailing zeroes.
bool doesItHaveDesiredZero(int mid, int n) {
    int zeros = 0;
    while (mid) {
        zeros += (mid / 5);
        mid /= 5;
    }

    return zeros >= n;
}

int findNum(int n) {
    // BS Approach
    int start = 0, end = INT_MAX;
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (doesItHaveDesiredZero(mid, n)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}