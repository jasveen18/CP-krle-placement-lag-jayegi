/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Maximize Chocolates.
int Solution::nchoc(int B, vector<int> &A) {
    priority_queue<int> maxHeap;
    int mod = 1e9 + 7;

    for (int i = 0; i < A.size(); i++)
        maxHeap.push(A[i]);

    long long ans = 0;

    while (B) {
        int cost = maxHeap.top();
        maxHeap.pop();

        ans += cost % mod;
        maxHeap.push(cost / 2);
        B--;
    }

    return ans % mod;
}
