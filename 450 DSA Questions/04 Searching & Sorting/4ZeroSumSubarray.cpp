/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement -  to count subarrays with sum equal to 0.
ll findSubarray(vector<ll> arr, int n ) {
    unordered_map<ll, ll> prefixSum;
    ll runningSum = 0;
    ll ans = 0;

    // Insert zero at first
    prefixSum[0] = 1;

    // Now check for each element
    for (int i = 0; i < n; i++) {
        runningSum += arr[i];
        if (prefixSum.find(runningSum) != prefixSum.end())
            ans += prefixSum[runningSum];
        prefixSum[runningSum]++;
    }

    return ans;
}