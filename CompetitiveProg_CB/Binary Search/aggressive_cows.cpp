bool cowsRakhPaaye(vector<int> &stalls, int n, int cowsToPlace, int minSeperation) {
    // Check if we can fit the cows at minSeperation distance.
    int cowsPlaced = 1, lastCowPlaced = stalls[0];

    for (int i = 1; i < n; i++) {
        // Check for min placement but greater than mid.
        if (stalls[i] - lastCowPlaced >= minSeperation) {
            cowsPlaced++;
            lastCowPlaced = stalls[i];
        }
    }

    // Check if we could place all the cows.
    if (cowsPlaced < cowsToPlace)
        return false;
    else
        return true;
}

int aggresiveCows (vector<int> &stalls, int cowsToPlace) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    // BS on the search space
    int low = 1, high = (stalls[n - 1] - stalls[0]), ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if we can place the cows with the current seperation.
        if (!cowsRakhPaaye(stalls, n, cowsToPlace, mid)) {
            high = mid - 1;
        } else {
            ans = mid;
            low = mid + 1;
        }
    }

    return ans;
}