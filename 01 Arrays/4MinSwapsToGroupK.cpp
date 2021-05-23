int minSwap(int *arr, int n, int k)
{
    // Count number of valid numbers in the array
    int validNums = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            validNums++;
    }

    // Count the non-valid nums in a window of count len
    int nonValidNums = 0;
    for (int i = 0; i < validNums; i++)
    {
        if (arr[i] > k)
            nonValidNums++;
    }

    int minSwaps = nonValidNums;
    for (int i = 1; i < n - validNums + 1; i++)
    {
        // If non valid number if out of window
        if (arr[i - 1] > k)
            nonValidNums--;

        // If non valid number enters the window
        if (arr[i + validNums - 1] > k)
            nonValidNums++;

        minSwaps = min(minSwaps, nonValidNums);
    }

    return minSwaps;
}