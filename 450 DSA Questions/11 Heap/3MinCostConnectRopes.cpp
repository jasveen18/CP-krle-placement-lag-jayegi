/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {
    if (n == 1)
        return 0;

    // sort(arr, arr+n);
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
    }

    long long cost = 0;

    while (minHeap.size() > 1) {
        long long first = minHeap.top(); minHeap.pop();
        long long second = minHeap.top(); minHeap.pop();

        cost += (first + second);
        minHeap.push(first + second);
    }

    return cost;
}