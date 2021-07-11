/******************************************
* AUTHOR : ARPIT *
* NICK : arpitfalcon *
* INSTITUTION : BIT MESRA *
******************************************/

// Problem Statement - Profit Maximization
int Solution::solve(vector<int> &A, int B) {
    priority_queue<int> maxHeap;

    for (int i = 0; i < A.size(); i++)
        maxHeap.push(A[i]);

    int ans = 0;

    while (B) {
        int cost = maxHeap.top();
        maxHeap.pop();

        ans += cost;
        maxHeap.push(cost - 1);
        B--;
    }

    return ans;
}
