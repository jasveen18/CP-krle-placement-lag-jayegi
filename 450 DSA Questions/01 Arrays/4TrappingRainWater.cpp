int trappingWater(int arr[], int n) {
    int leftMax[n] = {0};
    int rightMax[n] = {0};

    int waterStored = 0;

    // Calculate the left max
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(arr[i], leftMax[i - 1]);
    }

    // Calculate the right max
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }

    // Calculate water stored
    for (int i = 1; i < n - 1; i++) {
        waterStored += min(leftMax[i], rightMax[i]) - arr[i];
    }

    return waterStored;
}